/**
 * File : quick_sort.cc
 * Brief : 快速排序
*/

/**
 * 最坏时间复杂度： O(n^2), 每次分区的枢纽都是当前区间中最小的
 * 最好时间复杂度： O(nlogn),每次分区都能均匀的将区间分为两个
 * 平均时间复杂度： O(nlogn)
 * 空间复杂度：
 *  快速排序在系统内部需要一个栈来实现递归。若每次划分较为均匀，则其递归树的高度为 O(lgn)，
 *  故递归后需栈空间为 O(lgn)。最坏情况下，递归树的高度为 O(n)，所需的栈空间为 O(n)。
 * 稳定性：
 *  不稳定排序
*/

#include <iostream>
#include <vector>
using namespace std;


int partition(int arr[], int low, int high)
{
    int i = low, j = high;
    int pivot = arr[low];
    int finalpos = low;
    while(i < j) {
        while(i < j && arr[j] >= pivot) {
            j--;
        }
        if(i < j) {
            finalpos = j; //此时若退出循环，则最终位置为j
            arr[i++] = arr[j];
        }
        while(i < j && arr[i] <= pivot) {
            i++;
        }
        if(i < j) {
            finalpos = i; //此时若退出循环，则最终位置为i
            arr[j--] = arr[i];
        }
    }
    arr[finalpos] = pivot;
    return finalpos;
}

void quickSortR(int arr[], int low, int high)
{
    if(low < high) {
        int pivot = partition(arr, low, high);
        quickSortR(arr, low, pivot-1);
        quickSortR(arr, pivot + 1, high);
    }
}

void quickSort(int arr[], int size)
{
    int low = 0, high = size - 1;
        quickSortR(arr, low, high);
}



int main()
{
    int arr[] = {6,2,3,7,8,9,12,3,4,2};
    quickSort(arr, 10);
    for(int i = 0; i < 10; i++) {
        cout << arr[i] << " " ;
    }
}