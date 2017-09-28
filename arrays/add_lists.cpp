#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;


/*
string longestSSWRC(string s) {
    map<char, int> m;
    int size = 0;
    int l = 0;
    int h = 0;
    for(int i = 0; i < s.size(); i++) {        
        if(m.find(s[i]) != m.end()) {
            if(size > (h - l)) {
                
            }
            else {
                size = (h - l);
            }
        }
        else {
            m.insert(std::pair<char, int>(s[i],1) );
            h = i;
            size++;
        }
    }
    return s.substr(l_m,h_m+1);
}
*/

vector<int> op(vector<int> a, vector<int> b) {
    int i = 0;
    int j = 0;
    vector<int> r;
    size_t as = a.size();
    size_t bs = b.size();
    while( (i < as) && (j < bs) ) {
        int tot = a[i] + b[j];
        int rem= tot%10;
        int div = tot/10;
        if(div){
            r.push_back(1);
        }
        r.push_back(rem);
        i++; j++;
    }
    
    while( i < as) {
        r.push_back(a[i++]);    
    }
    
    while( j < bs) {
        r.push_back(b[j++]);    
    }
    
    return r;
}

int main(){
    int a1[] = {1,2,3,4,5,6};
    int b1[] = {2,3,4,5,6,7,8};
    vector<int> a(a1, a1 + sizeof(a1)/sizeof(a1[0]));
    vector<int> b(b1, b1 + sizeof(b1)/sizeof(b1[0]));
    vector<int> v = op(a,b);    
    for( int i = 0; i < v.size(); i++) {
        cout << " " << v[i];
    }
    cout << endl;
    //cout << longestSSWRC(s) << endl;
}
