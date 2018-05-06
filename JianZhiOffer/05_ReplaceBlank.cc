/**
 * 字符串：将字符串中的每个空格替换成“%20”
*/

#include <cstdio>
#include <cstring>

// 复习
void review()
{
    const char * str1 = "Hello World";
    const char * str2 = "Hello World";
    // str1和str2的值是一样的，都指向了常量区的“Hello World”, 任何对其的修改都是不起作用的
    // 所以C++要求需要加上const，不然出现警告

    char str3[] = "Hello World";
    // 开辟栈区，把字符串拷贝进去，可以修改
}

void ReplaceBlank(char str[], int length) //length表示字符串长度
{
    if(str == nullptr || length == 0)
        return;

    int originLength = 0;
    int countOfBlank = 0;
    int i = 0;
    while(str[i] != '\0' && i <= length) {
        originLength++;
        if(str[i] == ' ')
            countOfBlank++;
        ++i;
    }

    int newLength = originLength + countOfBlank * 2;
    if(newLength > length)
        return;

    int indexOfOriginal = originLength;
    int indexOfNew = newLength;
    while(indexOfOriginal >= 0 && indexOfNew > indexOfOriginal) {
        if(str[indexOfOriginal] == ' ') {
            str[indexOfNew--] = '0';
            str[indexOfNew--] = '2';
            str[indexOfNew--] = '%';
        } else {
            str[indexOfNew--] = str[indexOfOriginal]; //自减不要写在这里
        }
        indexOfOriginal--;
    }
}

int main()
{
    char str[20] = "We are good";
    ReplaceBlank(str, (sizeof str)/sizeof(char));
    printf("%s\n", str);

    char str1[20] = " We are good";
    ReplaceBlank(str1, (sizeof str1)/sizeof(char));
    printf("%s\n", str1);

    char str2[30] = " We are good ";
    ReplaceBlank(str2, (sizeof str2)/sizeof(char));
    printf("%s\n", str2);

    char *str3;
    ReplaceBlank(str3, (sizeof str3)/sizeof(char));
    // printf("%s\n", str3);
}