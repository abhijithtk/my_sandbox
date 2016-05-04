#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <queue>
#include <sstream>

using namespace std;

const int M = 5;
const int N = 5;

void printMat(int mat[][N]) {
    for(int i = 0; i < M; i++) {
        for(int j = 0; j < N; j++) {
            cout << " " << mat[i][j];
        }
        cout << endl;
    }
}

bool isValid(int mat[][N], int visited[][N], int i, int j) {
    if(i >=0 && i < M && j >= 0 && j < N && !visited[i][j] && mat[i][j])
        return true;
    return false;
}

void floodfill(int mat[5][5]) {
    int visited[M][N] = {{0,0,0,0,0},
    {0,0,0,0,0},
    {0,0,0,0,0},
    {0,0,0,0,0},
    {0,0,0,0,0}};
    
    queue<pair<int,int> > q;
    q.push(pair<int,int>(0,0));
    while(!q.empty()) {
        pair<int,int> p = q.front();
        int i = p.first;
        int j = p.second;
        q.pop();
        if(isValid(mat,visited,i,j)) {
            visited[i][j] = 1;
            mat[i][j] = 2;
            q.push(pair<int,int>(i - 1, j - 1));
            q.push(pair<int,int>(i - 1, j));
            q.push(pair<int,int>(i - 1, j+1));
            q.push(pair<int,int>(i, j -1));
            q.push(pair<int,int>(i, j + 1));
            q.push(pair<int,int>(i + 1, j - 1));
            q.push(pair<int,int>(i + 1, j));
            q.push(pair<int,int>(i + 1, j + 1));
        }
    }
}


int main(){
    /*
    int mat[4][4] = {   {1,2,3,4},
                        {5,6,7,8},
                        {9,10,11,12},
                        {13,14,15,16}};
    */
    int mat[][N] = {
        {1, 0, 0, 1, 0},
        {1, 0, 0, 1, 0},
        {0, 1, 0, 0, 1},
        {0, 1, 0, 0, 0},
        {0, 0, 0, 1, 1}
    };
    floodfill(mat);
    printMat(mat);
}
