/**
 * 数值的整数次方
*/

/**
 * 实现函数double Power(double base, int exponent), 求base的exponent次方。
 * 不要使用库函数，同时不需要考虑大数问题
 * 
 * 注意点：
 *    指数为负值，0
 *    底数为0，同时指数小于0，会产生除0， 非法
*/
#include <iostream>
using namespace std;

bool g_InvalidInput = false;

double PowerUnsigned(double base, unsigned int exp)
{
    double result = 1.0;
    for(int i = 1; i <= exp; ++i) {
        result *= base;
    }

    return result;
}

double Power(double base, int exp)
{
    if(base == 0.0 && exp < 0)
    {
        g_InvalidInput = true;
        return 0.0;
    }

    unsigned int absExp = (exp < 0) ? (unsigned int)(-exp) : (unsigned int)exp;

    double result = PowerUnsigned(base, absExp);
    if(exp < 0)
        result = 1.0 / result;
    
    return result;
}

int main()
{
    cout << "2.0 ^ 2 = " << Power(2.0, 2) << endl;
    cout << "(-2.0) ^ 2 = " << Power(-2.0, 2) << endl;
    cout << "0 ^ 2 = " << Power(0, 2) << endl;
    cout << "2.0 ^ -2 = " << Power(2.0, -2) << endl;
    cout << "2.0 ^ 0 = " << Power(2.0, 0) << endl;  
    cout << "0 ^ 0 = " << Power(0, 0) << endl;
}
