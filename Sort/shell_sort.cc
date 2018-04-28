/**
 * 希尔排序
*/

#include <iostream>

using namespace std;

void swap(int arr[], int i, int j)
{
	int tmp = arr[i];
	arr[i] = arr[j];
	arr[j] = tmp;
}

void shellSort(int arr[], int size) 
{
	if(arr == NULL || size == 0) 
		return;

	int d;
	for(int d = size / 2; d > 0; d = d/2) { 
		for(int i = d; i < size - 1; i++) {
			for(int j = i-d; j >= 0; j -= d) {
				if(arr[j] > arr[j+d]) {
					swap(arr, j, j+d);
				}
			}
		}
	}
}

int main()
{
	int a[] = {2, 5, 7, 2, 4, 8, 1, 9, 10};
	shellSort(a, 9);
	for(int i = 0; i < 9; i++) {
		cout << a[i] << " ";
	}
	cout << endl;
}