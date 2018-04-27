/**
 * 归并排序
*/

/**
 * 稳定性： 稳定排序
 * 数据结构要求： 可以是数组，也可以是链表
 * 额外空间要求： 辅助数组 O(N); 如果是链表可以实现原地排序
 * 时间复杂度： 对于长度为n的文件，最好情况或者最坏情况都需要NlogN
*/

#include <iostream>
using namespace std;

/**
 * 将两个区间归并为有序，空间复杂度为O(n) 
*/
void merge(int unsorted[], int low, int mid, int high)
{
    int sorted[high - low + 1];

    int i = low, j = mid + 1, k = 0;
    while(i <= mid && j <= high) {
        if(unsorted[i] < unsorted[j]) {
            sorted[k++] = unsorted[i++];
        } else {
            sorted[k++] = unsorted[j++];
        }
    }
    while(i <= mid) {
        sorted[k++] = unsorted[i++];
    }

    while(j <= high) {
        sorted[k++] = unsorted[j++];
    }

    i = low; 
    j = 0;
    while(i <= high) {
        unsorted[i++] = sorted[j++];
    }
}

/**
 * 一次归并过程，步长设置为step
*/
void mergeOnce(int unsorted[], int step, int size)
{
    int i;
    for(i = 0; i + 2 * step - 1 < size; i = i + 2 * step) {
        merge(unsorted, i, i + step -1, i + 2 * step - 1);
    }
    if(i + step - 1 < size - 1) {
        merge(unsorted, i, i + step - 1, size - 1);
    }
}

/**
 * 归并排序(自底向上)
*/
void mergeSortUp(int unsorted[], int size)
{
    for(int step = 1; step < size; step *= 2)
    {
        mergeOnce(unsorted, step, size);
    }
}

/**
 *  归并排序（自顶向下）
 *      递归实现
*/
void mergeRecur(int unsorted[], int low, int high)
{
    int mid;
    if(low < high) { // 区间长度大于1
        mid = (low + high) / 2;
        mergeRecur(unsorted, low, mid);
        mergeRecur(unsorted, mid + 1, high);
        merge(unsorted, low, mid, high);
    }
}
void mergeSortDown(int unsorted[], int size)
{
    if(unsorted == NULL) 
    {
        cout << "error : unsorted is NULL";
        return;
    }

    mergeRecur(unsorted, 0, size - 1);
}


int main()
{
    int a[] = {2,1,4, 5, 3, 9, 10, 8, 7, 38, 7};
    // merge(a, 0, 3, 7);
    // mergeOnce(a, 1, 11);
    mergeSortDown(a, 11);
    for(int i = 0; i < 11; i++) {
        cout << a[i] << ' ';
    }
    cout << endl;
}