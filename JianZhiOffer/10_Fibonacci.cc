/**
 * 斐波那契数列
*/
#include <iostream>
using namespace std;

long long Fibonacci(unsigned int n)
{
    int res[2] = {0, 1};
    if(n < 2)
        return res[n];

    long long PrePre = 0;
    long long Pre = 1;
    long long Cur = 0;
    for(unsigned int i = 2; i <= n; ++i) {
        Cur = PrePre + Pre;

        PrePre = Pre;
        Pre = Cur;
    }

    return Cur;
}

int main()
{
    cout << Fibonacci(10) << endl;
}