/**
 * 二分查找及其变形
*/
#include <iostream>
using namespace std;


/**
 * 基本二分查找，递归实现
 * 查找不到，返回-1；
*/

int bsearch1(int arr[], int low, int high, int target)
{
    if(low > high)
        return -1;

    int mid = (low + high) / 2;
    if(arr[mid] < target) {
        return bsearch1(arr, mid + 1, high, target);
    } else if(arr[mid] > target) {
        return bsearch1(arr, low, mid - 1, target);
    } else {
        return mid; //后递归
    }
}

/**
 * 基本二分查找，非递归实现
 * 查找不成功，返回-1
 * 
 * 后递归转化为非递归形式，不需要入栈
*/

int bsearch2(int arr[], int low, int high, int target)
{
    while(low <= high) {
        int mid = (low + high) / 2;
        if(arr[mid] > target) {
            high = mid - 1;
        } else if(arr[mid] < target) {
            low = mid + 1;
        } else {
            return mid;
        }
    }
    return -1;
}

/**
 * 查找目标下界（小于目标的最大数）
 * 
*/

int bsearch3(int arr[], int low, int high, int target)
{
    int mid = (low + high + 1) / 2;
    while(low < high) {
        if(arr[mid] >= target) {
            high = mid - 1;
        } else {
            low = mid; //mid还是备选，不需要+1
        }
        mid = (low + high + 1) / 2;        
    }

    if(arr[mid] >= target){
         return -1;
    } else {
        return mid;
    }
}

/**
 * 查找目标上界（大于目标的最小值）
*/

int bsearch4(int arr[], int low, int high, int target)

{
    while(low < high) {
        int mid = (low + high) / 2;
        if(arr[mid] <= target) {
            low = mid + 1;
        } else {
            high = mid; // mid还是备选
        }
    }

    if(arr[high] <= target) {
        return -1;
    } else {
        return high;
    }
}

/**
 * 旋转数组查找
*/

int bsearchOnRotateArray(int arr[], int low, int high, int target)
{
    while(low <= high) //注意为小于等号
    {
        int mid = (low + high) / 2;
        if(target < arr[mid]) { 
            if(arr[mid] >= arr[low]) { // mid处于第一个半坡，使用>=arr[low],而不是使用>arr[high]
                if(target >= arr[low]) { //判断target所属半坡
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            } else{ 
                low = mid + 1;
            }
        } else if(target > arr[mid]){
            if(arr[mid] >= arr[low]) {
                low = mid + 1;
            } else {
                if(target <= arr[high]) {
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }
        } else {
            return mid;
        }
    }

    return -1;
}

/**
 * 旋转数组返回最小元素(无重复元素)
*/

int minOfRotateArray(int arr[], int size) {
    int low = 0;
    int high = size - 1;

    while(arr[low] > arr[high]) {
        int mid = (low + high) / 2;
        if(arr[mid] < arr[low]) {
            high = mid;
        } else {
            low = mid + 1;
        }
    }
    return arr[low];
}


int main()
{
    int arr[] = {1, 2, 3, 5, 6, 7, 8, 9, 10};
    cout << bsearch1(arr, 0, 8, 3) << endl;
    cout << bsearch2(arr, 0, 8, 3) << endl;
    cout << bsearch3(arr, 0, 8, 7) << endl;
    cout << bsearch4(arr, 0, 8, 3) << endl;
    
    cout << bsearch1(arr, 0, 8, 11) << endl;
    cout << bsearch2(arr, 0, 8, 11) << endl;
    cout << bsearch3(arr, 0, 8, 1) << endl;
    cout << bsearch4(arr, 0, 8, 9) << endl;

    int arr1[] = {5, 6, 7, 8, 9, 10,1, 2, 3};
    cout << bsearchOnRotateArray(arr1, 0, 8, 0) << endl;
    cout << minOfRotateArray(arr1, 9) << endl;
}