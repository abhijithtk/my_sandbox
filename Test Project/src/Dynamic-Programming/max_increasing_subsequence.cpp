#include <stdio.h>
#include <vector>
#include <iostream>

using namespace std;
// max increasing  sequence
int mis(int arr[],int size) {
    
    vector<int>     v;
    vector<int>     r;
    for(int i = 0; i < size; i++) {
        v.push_back(arr[i]);
        r.push_back(i);
    }
    
    for(int i = 1; i < size; i++) {
        for(int j = 0; j < i; j++) {
            if(arr[j] < arr[i]) {
                if(v[i] < v[j] + arr[i]) {
                    v[i]    = v[j] + arr[i];
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
    int arr[] = {1, 101, 2, 3, 100, 4, 5};
    int size = sizeof(arr)/ sizeof(arr[0]);
    cout << "LIS=" << mis(arr,size) << endl;

    return 0;
}
