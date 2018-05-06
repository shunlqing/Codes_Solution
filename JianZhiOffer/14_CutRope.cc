/**
 * 剪绳子
 * 
 * 长度为n,剪成m段，乘积最大(n>1, m>1)
*/

#include <iostream>
using namespace std;

/**
 * 思路1：动态规划
 * 思路2：贪心
*/

int maxSolution(int length)
{
    if(length < 2)
        return 0;
    if(length == 2)
        return 1;
    if(length == 3)
        return 2;

    int *dp = new int[length+1];
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 3; //不是长度为3的最大值，而是剪成了3

    int max = 0;
    for(int i = 4; i < length + 1; i++) {
        max = 0;
        for(int j = 1; j <= i/2; j++) {
            int tmp = dp[j] * dp[i-j];
            if(tmp > max) {
                max = tmp;
            }
        }
        dp[i] = max;
    }

    max = dp[length];
    delete[] dp;
    return max; 
}

//贪心算法
int maxSolution2(int length)
{
    
}

int main()
{
    cout << maxSolution(8) << endl;
}