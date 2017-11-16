#include <vector>
#include <queue>
#include <map>
#include <iostream>
#include <stack>
#include <functional>
#include <unordered_map>
#include <set>


using namespace std;

struct Interval {
    int start;
    int end;
	Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};


class Solution {
public:
    vector<Interval> merge1(vector<Interval>& intervals) {
    	std::vector<Interval> res;
    	if(intervals.size() == 0)
    		return res;
    	stack<Interval> s;
    	for(auto &i : intervals){
    		if(s.empty())
    			s.push(i);
    		else {
    			Interval top = s.top();
				if(top.end >= i.start) {
					s.pop();
					s.push(Interval(top.start, i.end));
				}
				else{
					s.push(i);
				}
    		}
    	}
    	while(!s.empty()){
    		res.insert(res.begin(), s.top());
    		s.pop();
    	}
    	return res;
    }
    vector<Interval> merge(vector<Interval>& intervals) {
    	std::vector<Interval> res;
    	if(intervals.size() == 0)
    		return res;
		sort(intervals.begin(), intervals.end(), [](Interval i1, Interval i2){return i1.start < i2.start;});
		res.push_back(intervals[0]);
		for(int i = 1; i < intervals.size();  i++){
			if(res.back().end < intervals[i].start)
				res.push_back(intervals[i]);
			else
				res.back().end = max(intervals[i].end, res.back().end);
		}
		return res;
    }
};

int main()
{
    vector<Interval> v{Interval(1,3), Interval(2,6), Interval(8,10), Interval(15,18)};
    Solution obj;
    //obj.solve(v);
    for(auto &i : obj.merge(v)) {
    	cout <<  i.start << " " << i.end << endl;
    }
}