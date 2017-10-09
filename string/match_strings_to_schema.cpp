#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <sstream>
 
using namespace std;
 
 
void getSplitString(string ip, char delim, vector<string>& v) {
    istringstream iss(ip);
    string buf;
    while(getline(iss, buf, delim)) {
        v.push_back(buf);
        cout << buf << endl;
    }
       
}
 
bool schemaMatch(string ip, string schema) {
    vector<string> v;
    getSplitString(ip,' ', v);
    if(v.size() != schema.length())
        return false;
    map<char, string> m;
    int i = 0;
    int j = 0;
    while( i < schema.length() && j < v.size())
    {
        cout << i <<  " " << j << endl;
        if(m.find(schema[i]) == m.end()) {
            m.insert(pair<char, string>(schema[i], v[j]));
        }
        else {
            if(m[schema[i]] != v[j])
                return false;
        }
        i++; j++;      
    }
    return true;
}
   
int main(){
    cout << schemaMatch("dog dog cat", "bba") << endl;
}
