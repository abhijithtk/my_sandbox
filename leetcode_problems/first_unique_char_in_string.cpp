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
    int firstUniqChar(string s) {
        if(s.empty())
            return -1;
        unordered_map<char, pair<int, int>> countMap;
        for(int i = 0; i < s.size(); i++) {
        	if(countMap.find(s[i]) == countMap.end()) {
        		countMap.insert({s[i], {i, 1}});
        	}
        	else {
        		countMap[s[i]].second++;
        	}
        }
        int min = INT_MAX;
        for(auto o : countMap) {
        	if(o.second.second == 1)
        		min = std::min(min, o.second.first);
        }
        return min == INT_MAX? -1 : min;
    }
};

int main()
{
    string s("loveleetcode");
    Solution obj;
    //obj.solve(v);
    cout << obj.firstUniqChar(s) << endl;
}