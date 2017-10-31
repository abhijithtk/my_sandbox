#include <vector>
#include <queue>
#include <map>
#include <unordered_map>
#include <iostream>
#include <stack>
#include <functional>
#include <algorithm>

using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, std::vector<int>, less<int>> pq;

        for(auto &i : nums) {
            pq.push(i);
        }
        int ret;
        while(k > 0){
            ret = pq.top();
            cout << ret << endl;
            pq.pop();
            k--;
        }
        return ret;
    }
};

int main()
{
	int k =3;
    vector<int> v{2, 2,0, 1};
    Solution obj;
    cout << obj.findKthLargest(v, k) << endl;
}