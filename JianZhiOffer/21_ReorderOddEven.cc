/**
 * 调整数组顺序使奇数位于偶数前面
*/
#include <iostream>
using namespace std;

void ReorderOddEven(int *pData, unsigned int length)
{
    if(pData == nullptr || length <= 0)
        return;

    int* first = pData;
    int* last = pData + length - 1;

    while(first < last)
    {
        while(first < last && (*first % 2 == 1))
            ++first;
        
        while(first < last && (*last % 2 == 0))
            --last;

        if(first < last)
        {
            int tmp = *first;
            *first = *last;
            *last = tmp;
        }
    }
}

void test(int *data, int length)
{
    ReorderOddEven(data, length);

    if(data == nullptr)
        return;

    for(int i = 0; i < length; i++)
    {
        printf("%d\t", data[i]);
    }
    printf("\n");
}

int main()
{
    int data1[] = {1,2,3,4,5,6,7,8,9,10};
    int *data2 = nullptr;
    int data3[] = {1};
    test(data1, 10);
    test(data2, 1);
    test(data3, 1);

}
