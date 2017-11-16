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
	int dfs(vector<vector<int>>& matrix, int i, int j, int m, int n, vector<vector<int>>& cache){
		if(cache[i][j] != 0)
			return cache[i][j];
		int maxi = 1;
		int len = 0;
		int x = 0;
		int y = 0;
		x = i; y = j + 1;
		if(x >= 0 && x < m && y >= 0 && y < n && matrix[i][j] < matrix[x][y]) {
			len = dfs(matrix, i, j + 1, m, n, cache);
			maxi = max(1 + len, maxi);
		}
		x = i + 1; y = j;
		if(x >= 0 && x < m && y >= 0 && y < n && matrix[i][j] < matrix[x][y]) {
			len = dfs(matrix, i + 1, j, m, n, cache);
			maxi = max(1 + len, maxi);
		}
		x = i; y = j - 1;
		if(x >= 0 && x < m && y >= 0 && y < n && matrix[i][j] < matrix[x][y]) {
			len = dfs(matrix, i, j - 1, m, n, cache);
			maxi = max(1 + len, maxi);
		}
		x = i - 1; y = j;
		if(x >= 0 && x < m && y >= 0 && y < n && matrix[i][j] < matrix[x][y]) {
			len = dfs(matrix, i - 1, j, m, n, cache);
			maxi = max(1 + len, maxi);
		}
		cache[i][j] = maxi;
		return maxi;
	}

    int longestIncreasingPath(vector<vector<int>>& matrix) {
    	if(matrix.size() == 0)
    		return 0;

        int m = matrix.size();
        int n = matrix[0].size();
        std::vector<std::vector<int>> cache(m, vector<int>(n));

        int maxi = 1;
        for (int i = 0; i < m; ++i)
        {
        	for (int j = 0; j < n; ++j)
        	{
        		int len = dfs(matrix, i, j, m, n, cache);
        		maxi = max(len, maxi);
        	}
        }
        return maxi;
    }
};

int main()
{
    vector<vector<int> > v{
  {9,9,4},
  {6,6,8},
  {2,1,1}
};
    Solution obj;
    //obj.solve(v);
    cout << obj.longestIncreasingPath(v) << endl;
}