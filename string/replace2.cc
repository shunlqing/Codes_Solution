/**
 * 字符串的调整与替换
*/

/**
 * 题目：将字符数组的空格符用%20代替，字符数组空间足够用
 * 要求：
 *  时间复杂度为O（N）
 *  空间复杂度为O(1)
*/

#include <iostream>
#include <string.h>
using namespace std;


/**
 * 思路：
 *  先计算空格数目countSpace,然后直接定位到新字符数组的尾部，然后从后面开始复制
 *  处理遇到空格和不是空格两种情况
*/
void replace(char str[], int size) 
{
    int countSpace = 0;
    for(int i = 0; i < strlen(str); i++) {
        if(str[i] == ' ') {
            countSpace++;
        }
    }
    int j = strlen(str) + 2 * countSpace;
    int k = strlen(str);
    while(k >= 0) {
        if(str[k] != ' ') {
            str[j] = str[k];
            j--;
            k--;
        } else {
            str[j--] = '0';
            str[j--] = '2';
            str[j--] = '%';
            k--;
        }
    }
}

int main()
{
    char* pStr = (char*)malloc(100);
    const char* p = "I am a  student!";
    strncpy(pStr, p, strlen(p));
    replace(pStr, strlen(pStr));
    cout << pStr << endl;
}