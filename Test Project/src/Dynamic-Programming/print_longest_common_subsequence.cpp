#include<stdio.h>
#include<limits.h>
#include <iostream>
#include <string>

using namespace std;

#define R 6
#define C 7

void lcs(string m, string n) {
    int r = m.length();
    int c = n.length();
    int **mat = new int*[r + 1];
    for(int i = 0; i < r + 1; i++)  {
        mat[i] = new int[c + 1];
    }
    
    for(int i = 0; i <  r  + 1 ; i++) {
        for(int j = 0; j < c + 1; j++ ) {
            if(i == 0 || j == 0)
                continue;
            if(m[i - 1] == n[j - 1])
                mat[i][j] = mat[i -1][j - 1] + 1;
            else
                mat[i][j] = max(mat[i-1][j],mat[i][j -1]);
        }
    }
    cout << mat[R][C] << endl;
    for(int i = 0; i <  r  + 1 ; i++) {
        for(int j = 0; j < c + 1; j++ ) {
            cout << mat[i][j];
        }
        cout << endl;
    }
    int i = R;
    int j = C;
    string str;
    while(i > 0 && j > 0) {
        cout << "m=" << m[i - 1] << "n=" << n[j - 1] << endl;
        if(m[i - 1] == n[j - 1]) {
            str.push_back(m[i - 1]);
            i--;
            j--;
            continue;
        }
        if(mat[i-1][j] > mat[i][j-1]) {
            i--; continue;
        }
        else {
            j--; continue;
        }
    }
    cout << str << endl;
}

int main()
{
  char X[] = "AGGTAB";
  char Y[] = "GXTXAYB";
  lcs(X, Y);
  return 0;
}
