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
    int uniquePaths(int m, int n) {
        vector<vector<int>> matrix(m, vector<int>(n,0));
        for(int i = 0; i < m; i++)
        	matrix[i][0] = 1;
        for(int i = 0; i < n; i++)
        	matrix[0][i] = 1;
        for(int i = 1; i < m; i++) {
        	for (int j = 1; j < n; ++j)
        	{
        		matrix[i][j] = matrix[i][j - 1] + matrix[i - 1][j];
        	}
        }
        return matrix[m-1][n-1];
    }
};

int main()
{
    //vector<vector<char> > v{{'X','O','X','O','X','O'},{'O','X','O','X','O','X'},{'X','O','X','O','X','O'},{'O','X','O','X','O','X'}};
    Solution obj;
    //obj.solve(v);
    cout << obj.uniquePaths(4,4) << endl;
}