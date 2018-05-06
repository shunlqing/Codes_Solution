#include <iostream>
using namespace std;

/**
 * 题目一：找出数组中重复的数字
 * 
 * 长度为n的数组里的所有数字都在0 ～ n-1的范围内。找出任意一个重复的数字
 * 
 * 解法：
 *     将数据交换到对应下标的槽，时间复杂度为O(n)（因为每个元素最多被交换两次）
*/

bool duplicate(int number[], int length, int* duplication)
{
    if(number == nullptr || length == 0)
        return false;

    for(int i = 0; i < length; i++) {
        if(number[i] < 0 || number[i] >= length) {
            return false;
        }
    }

    for(int i = 0; i < length; i++) {
        while(number[i] != i) {
            if(number[i] == number[number[i]]) {
                *duplication = number[i];
                return true;
            }

            int tmp = number[i];
            number[i] = number[tmp];
            number[tmp] = tmp;
        }
    }

    return false;
}

void test1()
{
    //Normal
    int number[10] = {1, 3, 4, 2, 0, 3, 4, 6, 9, 8};
    int result;
    if(duplicate(number, 10, &result)) {
        cout << result << endl;
    } else {
        cout << "No duplication" << endl;
    }

    //No duplication
    int number1[10] = {1, 7, 4, 2, 0, 3, 5, 6, 9, 8};
    if(duplicate(number1, 10, &result)) {
        cout << result << endl;
    } else {
        cout << "No duplication" << endl;
    }

    //nullptr
    int *number2 = nullptr;
    if(duplicate(number2, 10, &result)) {
        cout << result << endl;
    } else {
        cout << "No duplication" << endl;
    }

    // length = 0
    int number3[10] = {1, 7, 4, 2, 0, 3, 5, 6, 9, 8};
    if(duplicate(number3, 0, &result)) {
        cout << result << endl;
    } else {
        cout << "No duplication" << endl;
    }

    //out of range
    int number4[10] = {1, 7, 4, 100, 0, 3, 5, 6, 9, 8};
    if(duplicate(number4, 0, &result)) {
        cout << result << endl;
    } else {
        cout << "No duplication" << endl;
    }
}

/**
 * 题目二 ： 不修改数组找出重复的数字
 * 
 * 思路1：使用辅助数组，按照题目1的思路解决。空间复杂度O(n), 时间复杂度O(n)
 * 思路2：二分查找
 * 
*/

int countRange(const int* numbers, int length, int low, int high)
{
    int count = 0;
    for(int i = 0; i < length - 1; i++) {
        if(numbers[i] <= high && numbers[i] >= low)
            count++;
    }

    return count;
}

int getDuplication(const int* numbers, int length)
{
    if(numbers == nullptr || length == 0)
        return -1;
    

    int low = 0;
    int high = length - 1;
    int mid;

    while(low <= high) {
        mid = (low + high) / 2;
        int count = countRange(numbers, length, low, mid);

        if(low == mid) {
            if(count > 1) {
                return low;
            } else {
                break;
            }
        }

        if(count > (mid - low + 1)) {
            high = mid;
        } else {
            low = mid + 1;
        }
    }

    return -1;
}

void test2()
{
    int result;
    
    int number[10] = {1, 3, 4, 2, 0, 3, 4, 6, 9, 8};
    if(result = getDuplication(number, 10) != -1) {
        cout << result << endl;
    } else {
        cout << "No duplication" << endl;
    }

    int *number1 = nullptr;
    if(result = getDuplication(number1, 10) != -1) {
        cout << result << endl;
    } else {
        cout << "No duplication" << endl;
    }

    int number2[10] = {1, 3, 4, 2, 0, 5, 7, 6, 9, 8};
    if(result = getDuplication(number2, 10) != -1) {
        cout << result << endl;
    } else {
        cout << "No duplication" << endl;
    }

}

int main()
{
    // Q1 test
    cout << "Test1..." << endl;
    test1();

    // Q2 test
    cout << "Test2..." << endl;    
    test2();
}