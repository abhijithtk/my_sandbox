#include <vector>
#include <queue>
#include <map>
#include <iostream>
#include <stack>
#include <functional>
#include <unordered_map>
#include <set>
#include <deque>

using namespace std;


class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        std::vector<int> res;
        deque<int> dq;
        for(int i = 0; i < nums.size(); i++) {
            while(!dq.empty() && nums[i] >= nums[dq.back()])
                dq.pop_back();
            dq.push_back(i);
            if(i >= k - 1)
                res.push_back(nums[dq.front()]);
            if(dq.front() <= i-k+1)
                dq.pop_front();
        }
        return res;

    }
};

int main()
{
	int k = 4;
    vector<int> v {1, 4, 2, 10, 2, 3, 1, 0, 20};
    Solution obj;
    //obj.solve(v);
    for(auto &i : obj.maxSlidingWindow(v, k)) {
        cout << i << endl;
    }
}