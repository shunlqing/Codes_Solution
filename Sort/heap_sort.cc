/**
 * File : heap_sort.cc
*/

/**
 * 堆排序
*/
#include <vector>
#include <iostream>
using namespace std;

void swap(vector<int>& vec, int i, int j)
{
    int tmp = vec[i];
    vec[i] = vec[j];
    vec[j] = tmp;
}

// 大顶堆
void fixDown(vector<int>& vec, int i, int size) {
    if(vec.size() < size || i >= size || vec.size() == 0) {
        return;
    }

    int left = 2 * i + 1;
    int right = 2 * i + 2;
    int largest = i;
    while(left < size) {
        if(vec[left] > vec[i]) {
            largest = left;
        }
        if(right < size && vec[right] > vec[largest]) {
            largest = right;
        }
        if(largest != i) {
            swap(vec, largest, i);
        } else {
            break;
        }
        i = largest;
        left = 2 * i + 1;
        right = 2 * i + 2;
    }
    return;
}

void fixUp(vector<int>& vec, int i) {
    int parent = (i-1)/2;

    while(parent >= 0) {
        if(vec[parent] <= vec[i]) {
            swap(vec, i, parent);
            if(parent == 0)
                break;
            i = parent;
            parent = (parent - 1)/2;
        } else {
            break;
        }
    }
}

void make_heap(vector<int>& vec, int size) {
    int i = (size - 2) / 2;
    while(i >= 0) {
        fixDown(vec, i, size);
        i--;
    }
}

void heapSort(vector<int>& vec, int size)
{
    make_heap(vec, vec.size());
    for(int i = vec.size() - 1; i >= 0; i--) {
        swap(vec, i, 0);
        fixDown(vec, 0, i);
    }
}

int main()
{
    vector<int> vec = {3, 5, 2, 7, 4, 0, 1, 7, 6};
    heapSort(vec, vec.size());
    for(auto x : vec) {
        cout << x << endl;
    }
}