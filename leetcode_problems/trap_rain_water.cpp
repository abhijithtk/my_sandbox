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
    int trap(vector<int>& height) {
    	std::vector<int> left_max(height.size());
    	std::vector<int> right_max(height.size());
    	std::vector<int> res;
    	int ans = 0;
    	if(height.size() == 0)
    		return 0;
    	left_max[0] = height[0];
    	right_max[height.size() - 1] = height[height.size() - 1];
    	for(int i = 1; i < left_max.size(); i++){
    		left_max[i] = max(height[i],left_max[i - 1]);
    	}
    	for(int i = right_max.size() - 2; i >= 0; i--){
    		right_max[i] = max(height[i],right_max[i + 1]);
    	}
    	for(int i = 0; i < height.size(); i++){
    		ans+= min(left_max[i],right_max[i]) - height[i];
    	}
    	return ans;
    }
};

int main()
{
    vector<int > v{0,1,0,2,1,0,1,3,2,1,2,1};
    Solution obj;
    cout << obj.trap(v) << endl;
}