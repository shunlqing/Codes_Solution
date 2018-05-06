/**
 * 在有序的二维数组中查找
 * 
 * 二维数组：
 *  每一行从左到右递增
 *  每一列从上到下递增
*/

#include <iostream>
using namespace std;

bool Find(int *matrix, int rows, int columns, int number)
{
    if(matrix == nullptr|| rows <= 0 || columns <= 0)
        return false;

    int row = 0;
    int column = columns - 1;
    while(row < rows && column >= 0) {
        if(matrix[row * columns + column] == number) {
            return true;
        } else if(matrix[row * columns + column] < number) {
            row++;
        } else {
            column--;
        }
    }
    
    return false;
}

class Ans {
public:
    void operator()(bool b) {
        cout << ((b) ? "Yes" : "No") << endl;
    }
};

int main()
{
    int matrix[16] = {
        1, 2, 8, 9,
        2, 4, 9, 12,
        4, 7, 10, 13,
        6, 8, 11, 15
    };

    Ans ans;
    ans(Find(matrix, 4, 4, 10)); // Yes
    ans(Find(matrix, 4, 4, 99)); // No
    ans(Find(nullptr, 4, 4, 10)); // No

}