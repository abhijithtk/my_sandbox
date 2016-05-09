#include <stdio.h>
#include <vector>
#include <iostream>

using namespace std;

int lis(int arr[],int size) {
    
    vector<int>     v;
    vector<int>     r;
    for(int i = 0; i < size; i++) {
        v.push_back(1);
        r.push_back(i);
    }
    
    for(int i = 1; i < size; i++) {
        for(int j = 0; j < i; j++) {
            if(arr[j] < arr[i]) {
                if(v[i] < v[j] + 1) {
                    v[i]    = v[j] + 1;
                    r[i]    = j;
                }
            }
        }
    }
    
    int max = 0;
    int index = -1;
    for(int i = 0; i < size; i++) {
        if(v[i] > max) {
            max = v[i];
            index = i;
        }
    }

    int prev = -1;
    while(index != prev) {
        cout << arr[index] << endl;
        prev = index;
        index = r[index];
    }
    return max;
}

int main() {
    int arr[] = {10, 22, 9, 33, 21, 50, 41, 60};
    int size = sizeof(arr)/ sizeof(arr[0]);
    cout << "LIS=" << lis(arr,size) << endl;

    return 0;
}
