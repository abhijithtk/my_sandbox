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
    int largestRectangleArea(vector<int>& heights) {
    	stack<int> s;
    	int area = 0;
    	int max_area = 0;
    	int i = 0;
    	while( i < heights.size()) {
    		if(s.empty() || heights[s.top()] <= heights[i])
    			s.push(i++);
    		else {
    			int top = s.top();
    			s.pop();
    			cout << "HERE2" << endl;
    			area = heights[top] *  (s.empty() ? i : ( i - s.top()  - 1));
    			max_area = max(area, max_area);
    			cout << "HERE3" << endl;
    		}
    	}
    	cout << "HERE" << endl;
    	while(!s.empty()) {
			int top = s.top();
			s.pop();
			area = heights[top] *  (s.empty() ? i : ( i - s.top()  - 1));
			max_area = max(area, max_area);
    	}
    	return max_area;
    }
};

int main()
{
    vector<int> v{6, 2, 5, 4, 5, 1, 6};
    Solution obj;
    //obj.solve(v);
    cout << obj.largestRectangleArea(v) << endl;
}