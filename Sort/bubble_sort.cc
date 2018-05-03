/**
 * 冒泡排序
*/

#include <iostream>
using namespace std;

void swap(int arr[], int i, int j)
{
    int tmp = arr[i];
    arr[i] = arr[j];
    arr[j] = tmp;
}

int bubbleSort(int arr[], int size)
{
    for(int i = size - 1; i > 0; i--) {
        for(int j = 0; j < i; j++) {
            if(arr[j] > arr[j+1]) {
                swap(arr, j, j+1);
            }
        }
    }
}

int main()
{
    int arr[] = {3, 4,2, 7, 2, 7, 8, 2, 1};
    bubbleSort(arr, 9);
    for(int i = 0; i < 9; i++) {
        cout << arr[i] << endl;
    }
}