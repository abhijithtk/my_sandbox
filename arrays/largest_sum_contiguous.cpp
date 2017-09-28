#include <stdio.h>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
// max increasing  sequence

int lcs(int arr[], int size) {
    int curr = arr[0];
    int maxx = arr[0];
    for(int i = 1; i < size; i++) {
        curr = max(arr[i], curr + arr[i]);
        maxx = max(curr, maxx);
    }
    return maxx;
}

int main() {
    int arr[] =  {-2, -3, 4, -1, -2, 1, 5, -3};
    int size = sizeof(arr)/sizeof(arr[0]);
    cout << "Lcs=" << lcs(arr,size) << endl;
    return 0;
}
