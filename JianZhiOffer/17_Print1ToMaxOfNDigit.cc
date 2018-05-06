/**
 * 打印从1到最大的n位数
*/

/**
 * 陷阱：大数问题
*/

/**
 * 思路：字符串模拟加法
 * 注意点： 
 *  什么时候停止增加？ 99999。。。。。-->最高位溢出
 *  前面的0不应该打印，重载printf
 *  
 * 思路2:全排列递归的方法
*/

/**
 * 注意点：
 *  输入为负值，0
*/

#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

void printfNumber(char* number)
{
    int len = strlen(number);
    int i = 0;
    
    while(number[i] == '0' && i < len) {
        i++;
    }

    if(i == len) // 不打印0
    {
        return;        
    }

    while(i < len) {
        printf("%c", number[i]);
        i++;
    }
    printf("\t");
}

bool Increment(char* number) //最高位溢出，返回true
{
    bool isOverflow = false;

    int n = strlen(number);
    char c = 0;
    int bit = n - 1;
    for(;bit >= 0; --bit) {
        int newValue = number[bit] - '0' + c;
        newValue += (bit == n-1) ? 1:0;
        if(newValue >= 10) {
            if(bit == 0) {
                isOverflow = true;
            } else {
                newValue -= 10;
                c = 1;
                number[bit] = '0' + newValue;
            }
        } else {
            number[bit] = '0' + newValue;
            break;
        }
    }

    return isOverflow;
}

void Print1ToMaxNDigits(int n)
{
    if(n <= 0)
        return;

    char *number = new char[n+1];
    memset(number, '0', n);
    number[n] = '\0';

    while(!Increment(number)) {
        printfNumber(number);
        // printf("%s\n", number);
    }

    delete[] number;
}

/**
 * 全排列递归实现
*/
void Print1ToMaxNDigitsCore(char* number, int index, int& n)
{
    if(index == n) {
        printfNumber(number);
        return;
    }

    for(int i = 0; i < 10; i++) {
        number[index] = '0' + i;
        Print1ToMaxNDigitsCore(number, index + 1, n); 
    }
}

void Print1ToMaxNDigits_2(int n)
{
    if(n < 0) 
        return;

    char *number = new char[n + 1];
    memset(number, '0', n);
    number[n] = '\0';

    int index = 0;
    for(int i = 0; i < 10; i++) {
        number[index] = '0' + i;
        Print1ToMaxNDigitsCore(number, index + 1, n);
    }
}

int main()
{
    Print1ToMaxNDigits(3);
    printf("\n");
    Print1ToMaxNDigits_2(3);
}