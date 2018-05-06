/**
 * 矩阵中的路径
*/
#include <cstring>
#include <iostream>
using namespace std;

/**
 * 回溯法用递归
*/

bool hasPathCore(char* matrix, int rows, int cols, 
    int row, int col, const char* str, int pathLength, bool *map)
{
    if(str[pathLength] == '\0')
        return true;
    
    bool ret = false;
    if(row >= 0 && row < rows && col >= 0 && col <= cols 
        && matrix[row * cols + col] == str[pathLength] && !map[row * cols + col]) 
    {
        ++pathLength;
        map[row * cols + col] = true;

        ret = hasPathCore(matrix, rows, cols, row+1, col, str, pathLength, map)
            || hasPathCore(matrix, rows, cols, row-1, col, str, pathLength, map)
            || hasPathCore(matrix, rows, cols, row, col+1, str, pathLength, map)
            || hasPathCore(matrix, rows, cols, row, col-1, str, pathLength, map);

        if(!ret) {
            --pathLength;
            map[row * cols + col] = false;
        }
    }

    return ret;
}

bool hasPath(char* matrix, int rows, int cols, const char* str)
{
    if(matrix == nullptr || rows <= 0 || cols <= 0 || str == nullptr)
        return false;
    
    bool *map = new bool[rows * cols];
    memset(map, 0, (rows * cols) * sizeof(bool));
    bool result;

    int pathLength = 0;
    for(int row = 0; row < rows; row++) {
        for(int col = 0; col < cols; col++) {
            if(hasPathCore(matrix, rows, cols, row, col, str, pathLength, map)) {
                result = true;
            } 
        }
    }
    delete[] map;
    return result;
}

int main()
{
    char matrix[] = {
        'a', 'b', 't', 'g',
        'c', 'f', 'c', 's',
        'j', 'd', 'e', 'h'
    };

    if(hasPath(matrix, 3, 4, "hece")) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}