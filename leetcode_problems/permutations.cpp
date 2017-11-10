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
	vector<vector<int>> res;
	set<std::vector<int>> s;

	void permute(vector<int> nums, int l, int r)
	{
	   if (l == r)
	     s.insert(nums);
	   else
	   {
	       for (int i = l; i <= r; i++)
	       {
	          swap(nums[l], nums[i]);
	          permute(nums, l+1, r);
	          swap(nums[l], nums[i]); //backtrack
	       }
	   }
	}

    vector<vector<int>> permute(vector<int>& nums) {
    	permute(nums, 0, nums.size() - 1);
    	for(auto ss: s)
    		res.push_back(ss);
    	return res;
    }
};

int main()
{
    vector<int> v{1,2,3};
    Solution obj;
    //obj.solve(v);
    for(auto i : obj.permute(v))
    {
    	for(auto j: i){
    		cout << j << " ";
    	}
    	cout << endl;
    }
    //cout << obj.solve(v) << endl;
}