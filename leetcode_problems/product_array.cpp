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
	vector<int> productExceptSelf1(vector<int>& nums) {
		int tmp = 1;
		std::vector<int> v(nums.size());
		for(int i = 0; i < nums.size(); i++){
			v[i] = tmp;
			tmp = tmp * nums[i];
		}
		tmp = 1;
		for(int i = nums.size() - 1; i >= 0; i--){
			v[i] = tmp * v[i];
			tmp = tmp * nums[i];
		}
		return v;
	}

    vector<int> productExceptSelf(vector<int>& nums) {
        std::vector<int> v(nums.size());
        v[0] = 1;
        for(int i = 1; i < nums.size(); i++){
        	v[i] = nums[i - 1] * v[i - 1];
        }
        for(auto i : v)
        	cout << i << endl;
        int right = 1;
        for(int i = nums.size() - 1; i>= 0; i--){
        	v[i] = v[i] * right;
        	right = right * nums[i];
        }
        return v;
    }
};

int main()
{
    vector<int > v{1,2,3,4};
    Solution obj;
    //obj.solve(v);
    //cout << obj.solve(v) << endl;
    for(auto &i : obj.productExceptSelf1(v)){
    	cout << i << endl;
    }
}