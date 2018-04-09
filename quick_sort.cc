/**
 * File : quick_sort.cc
 * Brief : 快速排序 for vector
*/

/**
 * 快速排序思想： 分治法
 * 步骤：
 *  1. 分区函数：将给定区间分成两个区间
 *      1) 设置两个哨兵i,j
 *      2) 以首元素的值为基准数，
 *      3）左哨兵依次找大于等于基准数的元素，右哨兵依次向左找小于基准数的元素，两者找到一对，就交换
 *      4）左哨兵和右哨兵不断靠近，直到两者相遇。
 *      5) 交换首元素和j处的值
 *      6）返回js
 *  2. 递归
 *      1）分区，返回确定的j
 *      2）递归对左区间进行分区
 *      3）地柜对右区间进行分区
 * 
 * 算法复杂度： O(NlogN)
 *  第一层遍历N个元素，第二层递归虽然在两个区间，也是遍历N个元素；第三层也是遍历N个元素。。。。
 *  再来，第一层递归确定了1个元素的位置，第二层递归确定了2个元素的位置，第三层4个，第四层8个。。。。
 *  所以，显然是NlogN
 * 
*/

#include <iostream>
#include <vector>
using namespace std;


void exch(vector<int>& vec, int i, int j)
{
    int tmp = vec[i];
    vec[i] = vec[j];
    vec[j] = tmp;
}

int partition(vector<int> &vec, int lo, int hi)
{
    int i = lo, j = hi + 1;
    int v = vec[lo];
    while(true) {
        while(vec[++i] < v) {
            if(i == hi)
                break;
        }
        while(vec[--j] >= v) {
            if(j == lo)
                break;
        }
        if(i >= j)
            break;
        exch(vec, i, j);
    }
    exch(vec, lo, j);
    return j;
}

void quick_sort(vector<int>& vec, int lo, int hi)
{
    if(lo >= hi) 
        return;
    int j = partition(vec, lo, hi);
    quick_sort(vec, lo, j-1);
    quick_sort(vec, j+1, hi);
}

int main()
{
    vector<int> vec = {6,2,3,7,8,9,12,3,4,2};
    quick_sort(vec, 0, vec.size()-1);
    for(auto x : vec){
        cout << x << " " << endl;
    }
}