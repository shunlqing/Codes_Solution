/**
 * 面试题1： 赋值运算符
*/

#include <cstdio>
#include <cstdlib>
#include <cstring>

/**
 * 请为该类型添加赋值运算符
 * 
 * 注意点：
 *  1.返回值应该为CMyString&，以支持链式表达式
 *  2.参数为const类型，提高代码效率
 *  3.释放自己的内存
 *  4.判断传入的实例就是自己
 *  5.strlen不能对空指针使用，需要特别注意
 *  
 *  5.考虑异常安全（new分配时出现异常：先分配，再释放原来的m_pData）
*/
class CMyString {
public:
    CMyString(char* pData = nullptr);
    CMyString(const CMyString& str);
    ~CMyString(void) { 
        if(m_pData)
            delete m_pData;
    }

    void show() {
        if(m_pData) printf("%s\n", m_pData);
    }

    CMyString& operator=(const CMyString& rhs) {
        if(this == &rhs)
            return *this;
        int length = (rhs.m_pData == nullptr) ? 0 : strlen(rhs.m_pData); // strlen不能对null指针使用！！！！
        char* tmp = new char[length + 1]; 
        if(tmp == NULL)
            throw;
        strncpy(tmp, rhs.m_pData, length);
        tmp[length] = '\0';
        delete m_pData; // delete 0 合法
        m_pData = tmp;

        return *this; //别忘了写
    }

    // 异常安全的另一种写法
    // CMyString& operator=(const CMyString& rhs) {
    //     if(this != &rhs) {
    //         CMyString tmp(rhs);

    //         char* pTmp = m_pData;
    //         m_pData = tmp.m_pData;
    //         tmp.m_pData = pTmp;
    //     }

    //     return *this; //别忘了写。忘了写这句，在链式表达式会出错
    // }

private:
    char* m_pData;
};

CMyString::CMyString(char* pData): m_pData(pData)
{

}

CMyString::CMyString(const CMyString& str)
{
    if(str.m_pData == nullptr) {
        m_pData = nullptr;
        return;
    }
    int length = (str.m_pData == nullptr) ? 0 : strlen(str.m_pData);
    char* tmp = new char[length + 1];
    if(tmp == NULL)
        throw;
    strncpy(tmp, str.m_pData, length);
    tmp[length] = '\0';
    m_pData = tmp;
}

int main()
{   
    char *p = new char[100];
    strcpy(p, "HelloWorld");
    CMyString str(p);
    str.show();

    CMyString str1(str);
    str.show();

    CMyString str2;

    str2 = str1 = str2;
    str2.show();
}
