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
	// push everything into a map with counts
	// push everything in map into a PQ, so that it only has the values. we dont care about the task name
	// go through the PQ, and for n intervals, drain the PQ items. whenever you pop something from PQ, subtract 1 from PQ.top and add to temp.
	// so temp has balance of all the remaining items
	// readd temp , and repeat
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<int,int> m;
        for(auto c : tasks) {
            m[c - 'A']++;
        }
        priority_queue<int> pq;
        for(auto k : m) {
        	pq.push(k.second);
        }
        int time = 0;
        while(!pq.empty()) {
        	int i = 0;
        	std::vector<int> t;
        	while(i <= n) {
        		if(!pq.empty()) {
        			if(pq.top() > 1) {
        				t.push_back(pq.top() - 1);
        			}
    				pq.pop();
        		}
        		time++;
        		if(t.empty() && pq.empty())
        			break;
        		i++;
        	}
        	for(auto k : t) {
        		pq.push(k);
        	}
        }
        return time;
    }
};

int main()
{
    vector<char> v{'A','A','A','B','B','B'};
    Solution obj;
    //obj.solve(v);
    cout << obj.leastInterval(v, 2) << endl;
}
