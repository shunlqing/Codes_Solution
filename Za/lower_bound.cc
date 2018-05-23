/**
 * 下界
*/

#include <iostream>
using namespace std;

int lower_bound(int *arr, int length, int val)
{
    int low = 0;
    int high = length - 1;

    if(arr == nullptr || length <= 0)
    {
        return -1;
    }

    int mid;
    while(low < high)
    {
        mid = (low + high) / 2;
        
        if(arr[mid] < val)
        {
            low = mid + 1;
        }
        else 
        {
            high = mid;
        }
    }

    return arr[low];
}

int upper_bound(int* arr, int length, int val)
{
    if(arr == nullptr || length <= 0 )
        return -1;

    int low = 0;
    int high = length - 1;
    int mid = -1;
    while(low < high)
    {
        mid = (low + high + 1) / 2;
        if(arr[mid] > val)
        {
            high = mid - 1;
        }
        else {
            low = mid;
        }
    }
    return arr[low];
}

int main()
{
    int arr[] = {1,2,3,4,6,7,8,9,10,11};
    cout << lower_bound(arr, 10, 5) << endl;
    cout << lower_bound(arr, 10, -1) << endl;
    cout << lower_bound(arr, 10, 111) << endl;

    cout << upper_bound(arr, 10, 5) << endl;
    cout << upper_bound(arr, 10, -1) << endl;
    cout << upper_bound(arr, 10, 11) << endl;
    cout << upper_bound(arr, 10, 111) << endl;
}