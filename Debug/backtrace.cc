/**
 * backtrace
 * backtrace_symble
 * 
 * 打印调用栈
 * 需要使用编译选项 -rdynamic
*/

#include <execinfo.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>

#define SIZE 100

void dump_stack()
{
    int btnum = 0;
    void *btbuf[SIZE];
    char **btstrings = NULL;
    int i;

    btnum = backtrace(btbuf, SIZE);
    btstrings = backtrace_symbols(btbuf, btnum);
    if(btstrings == NULL)
    {
        printf("Backtrace failed: %d:%s \n", errno, strerror(errno));
    } else {
        printf("Backtraces, total %d items\n", btnum);
        for(i = 0; i < btnum; i++)
            printf("%s\n", btstrings[i]);

        free(btstrings);
    }
}

void start_working()
{
    printf("Start working...\n");
    dump_stack();
}

int main()
{
    printf("Start backtracing...\n");
    start_working();
    return 0;
}
