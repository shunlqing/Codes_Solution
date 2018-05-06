/**
 * 旋转数组的最小数字
*/

/**
 * 二分查找思想
*/

#include <iostream>
using namespace std;

int MinInRotate(int* numbers, int length)
{
    if(numbers == nullptr || length <= 0)
        throw;
    int min;
    int low = 0;
    int high = length - 1;
    int mid;
    while(low <= high) {
        mid = (low + high) / 2;
        if(numbers[mid] <= numbers[high] && numbers[low] <= numbers[mid]) {
            if(numbers[mid] == numbers[low] || numbers[mid] == numbers[high]) //三者相等，无法判断，做一次顺序查找
            {
                min = numbers[low];
                for(int i = 0; i < high; i++) {
                    if(min > numbers[i])
                        min = numbers[i];
                }
                break;
            } else {
                min = numbers[low];
                break;
            }
        } else if(numbers[mid] >= numbers[low]) {
            low = mid+1;
        } else {
            high = mid;
        }
    }

    return min;    
}

int main()
{
    int a1[] = {6,7,8,1,2,3,4};
    int a2[] = {1,1,1,1,1,1,1};
    int a3[] = {1,1,0,1};
    int a4[] = {6,7,8,1,2,3,4};
    int a5[] = {1};
    int a6[] = {1,2,3,4,5,6,7};    
    cout << MinInRotate(a1, 7);
    cout << MinInRotate(a2, 7);
    cout << MinInRotate(a3, 4);
    cout << MinInRotate(a4, 7);
    cout << MinInRotate(a5, 1);
    cout << MinInRotate(a6, 7);
    
}