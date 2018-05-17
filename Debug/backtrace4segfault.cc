/**
 * backtrace用于处理段错误
*/

/**
 * backtrace + ucontext_t
 * 
 * ucontext_t返回SEGV信号发生是的CPU信息，
 * 获取的到出错的pc指针
 * 对程序反编译获取该地址所指向的位置
 * 
 * 需要使用编译选项：-rdynamic
*/

#include <signal.h>  
#include <execinfo.h>  
#include <stdio.h>  
#include <stdlib.h>  
#include <ucontext.h>  
  
#define BTSIZE 100  

static void *getMcontextEip(ucontext_t *uc) { // 获取信号发生时的eip
    #if defined(__i386__)  
    return (void*) uc->uc_mcontext.gregs[14]; /* Linux 32 */  
    #elif defined(__X86_64__) || defined(__x86_64__)  
    return (void*) uc->uc_mcontext.gregs[16]; /* Linux 64 */  
    #elif defined(__ia64__) /* Linux IA64 */  
    return (void*) uc->uc_mcontext.sc_ip;  
    #endif 
}
  
static void sig_handler(int sig, siginfo_t *info, void *secret)  
{  
    ucontext_t *uc = (ucontext_t*) secret;  
  
    void *buffer[BTSIZE];  
    char **strings;  
    int nptrs = 0;  
  
    printf("in sig_handler\n");  
    printf("sig is %d, SIGSEGV is %d\n", sig, SIGSEGV);  
    printf("info.si_signo is %d, info.si_addr is %p\n",   
            info->si_signo, info->si_addr);  
  
    if (sig == SIGSEGV)  
    {  
        nptrs = backtrace(buffer, BTSIZE);  
        printf("backtrace() returned %d addresses\n", nptrs);  
  
        strings = backtrace_symbols(buffer, nptrs);  
        if (strings == NULL)   
        {  
            perror("backtrace_symbols");  
            exit(EXIT_FAILURE);  
        }  
  
        printf("backtrace: \n");  
        int j = 0;  
        for (j = 0; j < nptrs; j++)  
        {  
            printf("[%d]%s\n", j, strings[j]);  
        }  
        free(strings);  

        printf("seg fault eip: 0x%x\n", getMcontextEip(uc));
  
        exit(0);  
    }  
}  
  
void fun3()  
{  
    int *ptr = (int *)0x123;  
    printf("this is fun3\n");  
  
    *ptr = 0;  
}  
  
void fun2()  
{  
    printf("this is fun2\n");  
    fun3();  
}  
  
void fun1()  
{  
    printf("this is fun1\n");  
    fun2();  
}  
  
int main()  
{  
    struct sigaction act;  
    sigemptyset(&act.sa_mask);  
    act.sa_flags = SA_SIGINFO;  // 设置SA_SIGINFO得到更多信息，处理函数第三个参数为ucontext_t结构
    act.sa_sigaction = sig_handler;  
    sigaction(SIGSEGV, &act, NULL);  
  
    fun1();  
}