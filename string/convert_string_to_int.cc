/**
 * 将整型字符串转换为整型 
 * 题目来源：程序员代码面试指南
*/
#include <iostream>
using namespace std;

int convert(const string& str)
{
    bool negative_flag = false;
    int res = 0;
    for(int i = 0; i < str.size(); i++) {
        if(i == 0) {  // i==0为第一阶段，判断是否为负值，是否为0
            if(str[i] == '-') {
                negative_flag = true;
            } else if(str[i] == '0') {
                return 0;
            } else if(str[i] <= '9' && str[i] >= '1') {
                res += static_cast<int>(str[i] - '0');
            } else {
                return 0;
            }
        } else {
            if(str[i] <= '9' && str[i] >= '0') {
                int temp = res * 10 + static_cast<int>(str[i] - '0');
                if(temp < res) {  //检查是否溢出
                    return 0;
                } else {
                    res = temp;
                }
            } else {
                return 0;
            }
        }
    }

    return (negative_flag) ? (0-res) : res;
}

int main()
{
    cout << convert("0") << endl;
    cout << convert("123") << endl;
    cout << convert("A13") << endl;
    cout << convert("2147483647") << endl;
    cout << convert("2147483648") << endl;
    cout << convert("-123") << endl;
}