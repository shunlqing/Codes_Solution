/**
 * 转圈打印矩阵
*/

#include <iostream>
using namespace std;

void printEdge(int matrix[][4], int x1, int y1, int x2, int y2) // 二维数组需要指定大小
{
    if(x1 == x2) {
        for(int i = y1; i <= y2; i++) {
            cout << matrix[x1][i] << " ";
        }
    } else if(y1 == y2) {
        for(int i = x1; i <= x2; i++) {
            cout << matrix[i][y1];
        }
    } else {
        int curX = x1;
        int curY = y1;
        while(curY != y2) {
            cout << matrix[x1][curY] << " ";
            curY++;
        }

        while(curX != x2) {
            cout << matrix[curX][y2] << " ";
            curX++;
        }

        while(curY != y1) {
            cout << matrix[x2][curY] << " ";
            curY--; 
        }

        while(curX != x1) {
            cout << matrix[curX][y1] << " ";
            curX--;
        }
    }
}

void spiralOrderPrint(int matrix[][4], int size_x, int size_y) {
    int x1 = 0;
    int y1 = 0;
    int x2 = size_x - 1;
    int y2 = size_y - 1;
    while(x1 <= x2 && y1 <= y2) {
        printEdge(matrix, x1++, y1++, x2--, y2--);
    }
}

int main()
{
    int m[][4] = {{1,2,3,4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};
    spiralOrderPrint(m, 4, 4);
}