#include <vector>
#include <queue>
#include <map>
#include <iostream>
#include <stack>
#include <functional>
#include <unordered_map>
#include <set>
#include <list>
#include <unordered_set>


using namespace std;

class Solution {
public:
    string frequencySort(string s) {
    	unordered_map<char, int>  um;
    	for(auto c : s) {
    		um[c]++;
    	}
    	map<int, string> m;
    	for(auto o : um) {
    		m[o.second] += string(o.second, o.first);
    	}
    	string res;
    	auto mit = m.rbegin();
    	for( ; mit != m.rend(); mit++){
    		res += mit->second;
    	}
    	return res;
    }
};


int main()
{
    string s("Aabb");
    Solution obj;
    //obj.solve(v);
    cout << obj.frequencySort(s) << endl;
}