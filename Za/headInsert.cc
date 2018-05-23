/**
 * 最小堆的插入
*/

#include <iostream>
#include <vector>
using namespace std;

void swap(vector<int>& vec, int x, int y)
{
    int a = vec[x];
    vec[x] = vec[y];
    vec[y] = a;
}

void HeadInsert(vector<int>& heap, int val)
{
    heap.push_back(val);
    int cur = heap.size() - 1;

    int parent = (cur - 1) / 2;
    while(parent >= 0)
    {
        if(heap[cur] < heap[parent]) {
            swap(heap, cur, parent);
            cur = parent;
            if(parent == 0)
                break;
            parent = (parent - 1) / 2;
        } else {
            break;
        }
    }
    return;
}

int main()
{
    vector<int> heap = {2,4,6,7,8,9,12,10,9};
    HeadInsert(heap, 1);

    for(auto x : heap)
    {
        cout << x << " ";
    }
    cout << endl;
}