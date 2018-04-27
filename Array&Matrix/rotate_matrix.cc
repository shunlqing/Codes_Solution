/**
 * 顺时针旋转矩阵
*/
#include <vector>
#include <iostream>
using namespace std;


void rotateEdge(vector<vector<int>>& matrix, int x1, int y1, int x2, int y2)
{
    int times = y2 - y1; //需要旋转的次数
    int tmp = 0;
    for(int i = 0; i < times; i++) {
        tmp = matrix[x1+i][y1];
        matrix[x1+i][y1] = matrix[x2][y1+i];
        matrix[x2][y1+i] = matrix[x2-i][y2];
        matrix[x2-i][y2] = matrix[x1][y2-i];
        matrix[x1][y2-i] = tmp;
    }
}

void rotate(vector<vector<int>>& matrix)
{
    int x1 = 0;
    int y1 = 0;
    int x2 = matrix.size() - 1;
    int y2 = matrix[0].size() - 1;
    while(x1 < x2) {
        rotateEdge(matrix, x1++, y1++, x2--, y2--);
    }
}

int main()
{
    vector<vector<int>> m = {{1,2,3,4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};
    for(auto x : m) {
    for(auto y : x) {
        cout << y << " ";
    }
        cout << endl;
    }
    cout << endl;
    rotate(m);
    for(auto x : m) {
        for(auto y : x) {
            cout << y << " ";
        }
        cout << endl;
    }
    cout << endl;
}