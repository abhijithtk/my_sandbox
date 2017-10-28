#include <vector>
#include <queue>
#include <map>
#include <iostream>
#include <stack>
#include <functional>


using namespace std;

class Functor {
public:
	bool operator() (pair<string,int> &p1, pair<string, int> &p2) {
		return p1.second < p2.second || (p1.second == p2.second && p1.first > p2.first);
	}
};

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
    	map<string, int> m1;
    	for(auto &i : words){
    			m1[i]++;
    	}
    	std::vector<string> v;
    	priority_queue<pair<string, int>, vector<pair<string, int>>, Functor> pq;

    	for(auto &w : m1) {
    		pq.push(make_pair(w.first, w.second));
    	}
    	while(! pq.empty() && k > 0){
    		pair<string,int> p = pq.top();
    		cout << p.first <<  " " << p.second << endl;
    		v.push_back(p.first);
    		pq.pop();
    		k--;
    	}
    	return v;
    }
};

int main()
{
    vector<string> v{"the","world","is","the","playground","the","is","world", "is"};
    Solution obj;
    int k = 3;
    for(auto &i : obj.topKFrequent(v, k)){
		    cout << i << endl;
    }
}