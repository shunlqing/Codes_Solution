/**
 * n个整数的无序数组，找出每个元素后面第一个比它大的元素，要求时间复杂度为O(n)
*/

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> FindFirstBiggerThanCur(vector<int> &vec)
{
    vector<int> result(vec.size(), -1);
    if(vec.size() <= 1)
        return vector<int>(vec);
    
    stack<int> st;
    for(int i = 0; i < vec.size(); i++)
    {
        if(st.empty())
        {
            st.push(i);
            continue;
        }

        while(!st.empty()){
            if(vec[st.top()] < vec[i]) 
            {
                result[st.top()] = vec[i];
                st.pop();
            } 
            else
                break; 
        }
        
        st.push(i);
    }

    return result;
}

int main()
{
    vector<int> vec = {3,2,5,7,9,3,4,7,2,1,6,8};
    for(auto x : vec)
    {
        cout << x << " ";
    }
    cout << endl;
    auto res = FindFirstBiggerThanCur(vec);
    for(auto x : res)
    {
        cout << x << " ";
    }
    cout << endl;
}