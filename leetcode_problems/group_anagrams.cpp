#include <vector>
#include <queue>
#include <map>
#include <iostream>
#include <stack>
#include <functional>
#include <unordered_map>
#include <set>


using namespace std;


class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
    	unordered_map<string, multiset<string>> m;
    	for(auto &i: strs) {
    		string temp = i;
    		sort(temp.begin(), temp.end());
    		m[temp].insert(i);
    	}
    	vector<vector<string>> ret;
    	for(auto &i : m){
    		std::vector<string> temp;
    		for(auto &j: i.second){
    			temp.push_back(j);
    		}
    		ret.push_back(temp);
    	}
    	return ret;

    }
};

int main()
{
    vector<string> v{"eat","tea","tan","ate","nat","bat"};
    Solution obj;
    //obj.solve(v);
    vector<vector<string>> ret = obj.groupAnagrams(v);
    for(auto &i : ret){
    	for(auto &j : i){
    		cout << j << " ";
    	}
    	cout << endl;
    }
    //cout << obj.solve(v) << endl;
}