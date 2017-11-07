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
    int solve(vector<int>& vec, int k) {
    	int sum = 0;
    	for (int i = 0; i < k && i < vec.size(); ++i)
    	{
    		sum+=vec[i];
    	}
    	cout << sum << endl;
    	int maxsum = sum;
    	int left = 0;
    	for(int i = k; i < vec.size(); i++){
    		sum = (sum - vec[left++] + vec[i]);
    		maxsum = max(sum, maxsum);
    	}
    	return maxsum;
    }
};

int main()
{
	int k = 4;
    vector<int> v {1, 4, 2, 10, 2, 3, 1, 0, 20};
    Solution obj;
    //obj.solve(v);
    cout << obj.solve(v, k) << endl;
}