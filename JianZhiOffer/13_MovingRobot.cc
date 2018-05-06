/**
 * 机器人的运动范围
*/

#include <iostream>
using namespace std;

int getDigitSum(int number)
{
    int sum = 0;
    while(number > 0) {
        sum += number % 10;
        number /= 10;
    }

    return sum;
}

bool check(int threshold, int rows, int cols, int row, int col, bool *map)
{
    if(row >= 0 && row < rows && col >= 0&& col < cols 
        && getDigitSum(row) + getDigitSum(col) <= threshold  && !map[row * cols + col])
    {
        return true;
    }

    return false;
}

int movingCountCore(int threshold, int rows, int cols, int row, int col, bool* map)
{
    int count = 0;
    if(check(threshold, rows, cols, row, col, map)) {
        map[row * cols + col] = true;

        count = 1+ movingCountCore(threshold, rows, cols, row + 1, col, map)
                + movingCountCore(threshold, rows, cols, row - 1, col, map)
                + movingCountCore(threshold, rows, cols, row, col + 1, map)
                + movingCountCore(threshold, rows, cols, row, col - 1, map);
    }

    return count;
}

int movingCount(int threshold, int rows, int cols)
{
    if(threshold <= 0 || rows <= 0 || cols <= 0)
        return 0;
    
    bool *map = new bool[rows * cols];
    for(int i = 0; i < rows * cols; i++) {
        map[i] = false;
    }

    int count = movingCountCore(threshold, rows, cols, 0, 0, map);

    delete[] map;
    return count;
}



int main()
{
    cout << movingCount(18, 50, 50);
}