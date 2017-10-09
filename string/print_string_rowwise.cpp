#include<stdio.h>
#include<limits.h>
#include <iostream>
#include <string>

using namespace std;

void printZigZag(string s, int size) {
    string *arr = new string[size];
    if(size == 1) {
        cout << s << endl;
        return; 
    }
    bool down = true;
    int row = 0;
    for(int i = 0;  i < s.length(); i++ ) {
        arr[row].push_back(s[i]);
        if(row == size - 1) {
            down = false;
        }
        else if (row == 0) {
            down = true;
        }
        (down) ? row++ : row--;
    }
    for(int i = 0; i < size; i++) {
        cout << arr[i];
    }
    cout << endl;
}

int main() {
    printZigZag("GEEKSFORGEEKS",3);
    return 0;
}
