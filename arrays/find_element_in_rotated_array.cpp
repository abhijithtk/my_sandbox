#include<stdio.h>
#include<limits.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <list>
#include <queue>
#include <string.h>

using namespace std;

#define ROW 5
#define COL 5

int findXsection(vector<int>& a, vector<int> & b) {
    int i = 0; int j = 0;
    while(i < a.size() && j < b.size()) {
        if(a[i] == b[j]) 
            return a[i];
        else if (a[i] < b[j])
            i++;
        else
            j++;
    }
    return -1;
}

int bs(vector<int>& a, int l, int h, int k) {
    if(h >=l ) {
        cout << "h=" << h << ",l=" << l << endl;
        int mid = (l + h)/2;
        if(a[mid] == k)
            return mid;
        if(a[l] < a[mid]) {
            if(k >= a[l] && k <= a[mid])    
                return bs(a,l,mid-1,k);
            return bs(a,mid+1,h,k);
        }
        if(k >= a[mid] && k <= a[h])    
            return bs(a,mid+1,h,k);
        return bs(a,l,mid-1,k);
        
    }
    return -1;
}

int main() {
    vector<int> a = {4, 5, 6, 7, 8, 9, 1, 2, 3};
    cout << bs(a,0,a.size() - 1, 3) << endl;
}
