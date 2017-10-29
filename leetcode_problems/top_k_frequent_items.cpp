#include <vector>
#include <queue>
#include <map>
#include <iostream>
#include <stack>
#include <functional>

using namespace std;
class Functor {
public:
	bool operator() (const pair<int, int> &p1, const pair<int, int> &p2){
		return p1.second < p2.second;
	}
};

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
    	map<int, int> m;
    	for(auto &i : nums){
    		m[i]++;
    	}
    	priority_queue<pair<int, int>, std::vector<pair<int, int>>, Functor> pq;
    	map<int, int>::const_iterator mit;
    	for(mit = m.begin(); mit != m.end(); mit++){
    		pq.push(make_pair(mit->first, mit->second));
    	}

    	std::vector<int> res;
    	while(!pq.empty() && k>0){
    		res.push_back(pq.top().first);
    		pq.pop();
    		k--;
    	}
    	return res;
   }
};
int main()
{
	int k =2;
    vector<int> v{1,1,1,2,2,3};
    Solution obj;
    for(auto &i : obj.topKFrequent(v, k)) {
    	cout << i << endl;
    }

}