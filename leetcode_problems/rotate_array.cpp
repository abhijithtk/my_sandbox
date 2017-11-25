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
    void rotate(vector<int>& nums, int k) {
        if(k > nums.size())
            k = k % nums.size();
    	reverse(nums.begin(), nums.end());
	    reverse(nums.begin(), nums.begin() + k);
		reverse(nums.begin() + k, nums.end());
    }
};

int main()
{
    vector<int> v{1,2,3,4,5,6};
    Solution obj;
    for(auto i : v) {
    	cout << i << " ";
    }
    cout << endl;
    obj.rotate(v, 11);
    for(auto i : v) {
    	cout << i << " ";
    }
    cout << endl;
    //cout << obj.solve(v) << endl;
}