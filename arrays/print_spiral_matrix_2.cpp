#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <sstream>

using namespace std;
    
void printMat(int mat[4][4]) {
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++) {
            cout << " " << mat[i][j];
        }
        cout << endl;
    }
}
    
void printSpiralMat(int mat[5][5], int m, int n, int k) {
    if(m < 0 || n < 0)
        return;
    if(m == 1) {
        for(int i = 0; i < m; i++)
            cout << " " << mat[k][k+i];
        cout << endl;
        return;
    }
    if(n == 1) {
        for(int i = 0; i < m; i++)
            cout << " " << mat[k + i][k];
        cout << endl;
        return;
    }    
    cout << "m = " << m << "n = " << n << ", k = "<< k << endl;
    for(int i = 0; i < m - 1; i++)
        cout << " " << mat[k][k+i];
    cout << endl;
    for(int i = 0; i < n - 1; i++)
        cout << " " << mat[k + i][n - 1 + k];
    cout << endl;
    for(int i = n - 1;  i > 0; i--)
        cout << " "  << mat[m - 1 + k][i + k];
    cout << endl;
    for(int i = m - 1; i > 0; i--)
        cout << " " << mat[i + k][k];
    cout << endl;
    printSpiralMat(mat, m - 2, n - 2, k + 1);
}

int main(){
    /*
    int mat[4][4] = {   {1,2,3,4},
                        {5,6,7,8},
                        {9,10,11,12},
                        {13,14,15,16}};
    */
    int mat[5][5] = {
        {1,  2,  3,  4,  5},
        {6 , 7,  8,  9, 10},
        {11, 12, 13, 14, 15 },
        {16, 17, 18, 19, 20},
        {21, 22, 23, 24, 25}
    };
    printSpiralMat(mat,5,5,0);
}
