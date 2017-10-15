#include <vector>
#include <queue>
#include <map>
#include <iostream>

using namespace std;


class Solution {
public:
    int maxArea(vector<int>& height) {
        if(height.size() == 0)
            return 0;
    	int i = 0;
    	int j = height.size() - 1;
    	int area = 0;
    	while(i < j) {
    		area = std::max(area, min(height[i], height[j]) * (j - i));
    		if(height[i] < height[j])
    			i++;
    		else
    			j--;
    	}
    	return area;
    }
};

int main()
{
    vector<int> v{1, 8, 6, 2, 5, 4, 8, 3, 7};
    Solution obj;
    //obj.solve(v);
    cout << obj.maxArea(v) << endl;
}