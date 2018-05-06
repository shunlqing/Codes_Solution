/**
 * 位操作： 二进制中1的个数
*/

/**
 * 注意点：
 *  负数右移，最高位补1，保证仍是负数。0xfffffff右移1位仍是0xfffffff。使用左移0x01的方式比较。
 *  除法的效率很低，所以不要把右移操作转为除2操作
 *  
 * 思路1：
 *  使用0x01左移，依次比较。比较次数是类型的字长
 * 
 * 思路2：
 *  把一个整数减去1，再和原整数做与，可以消除最右边的1，变成0.
 *  基于此理论，最多执行次数为1的个数
 *  很多问题可以用这个思路解决！！！！！！！！
 *     例子：
 *     1.一条语句判断一个数是不是2的整数次方。这个数必然有且只有一位是1
 *     2.数字m需要更改多少位才能得到数字n。先异或，再统计1的个数。
*/

#include <iostream>
using namespace std;

int NumberOf1_1(int n)
{
    int flag = 0x01;
    int count = 0;
    while(flag) {
        if(n & flag) {
            count++;
        }

        flag = flag << 1;
    }
    
    return count;
}

int NumberOf1_2(int n)
{
    int count = 0;
    while(n) {
        count++;
        n = n & (n-1);
    }
    
    return count;
}

int main()
{
    cout << "0x01: " << NumberOf1_1(1) << endl;
    cout << "0x01: " << NumberOf1_2(1) << endl;
    cout << "0x7fffffff: " << NumberOf1_1(0x7fffffff) << endl;
    cout << "0x7fffffff: " << NumberOf1_2(0x7fffffff) << endl;
    cout << "0x80000000: " << NumberOf1_1(0x80000000) << endl;
    cout << "0x80000000: " << NumberOf1_2(0x80000000) << endl;
    cout << "0xffffffff: " << NumberOf1_1(0xffffffff) << endl;
    cout << "0xffffffff: " << NumberOf1_2(0xffffffff) << endl;
    cout << "0x0: " << NumberOf1_1(0) << endl;
    cout << "0x0: " << NumberOf1_2(0) << endl;    
}