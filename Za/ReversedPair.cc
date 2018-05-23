/**
 * 求一个乱序数组的逆序对
 * 逆序对：i < j,A[i] > A[j]
*/

#include <utility>
#include <vector>
#include <iostream>
using namespace std;

auto ReversedPair(vector<int>& vec)
{
    vector<pair<int, int>> ret;
    for(int i = 0; i < vec.size(); i++)
    {
        int index = i;
        int value = vec[i];

        if(value < vec.size() && vec[value] == index)
        {
            if(index > value)
                continue;
            ret.push_back(pair<int, int>(index, value));
        }
    }

    return ret;
}

int main()
{

}