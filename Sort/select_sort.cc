/**
 * 选择排序
*/

#include <iostream>
using namespace std;

void swap(int arr[], int i, int j)
{
    int tmp = arr[i];
    arr[i] = arr[j];
    arr[j] = tmp;
}

void selectSort(int arr[], int size)
{
    if(arr == NULL) {
        return;
    }

    int min = 0;
    for(int i = 0; i < size; i++) {
        min = i;
        for(int j = i + 1; j < size; j++) {
            if(arr[min] > arr[j]) {
                min = j;
            }
        }
        if(min != i) {
            swap(arr, i, min);
        }
    }
}

int main()
{
    int arr[] = {3, 4,2, 7, 2, 7, 8, 2, 1};
    selectSort(arr, 9);
    for(int i = 0; i < 9; i++) {
        cout << arr[i] << endl;
    }
}