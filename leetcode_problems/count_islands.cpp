#include <vector>
#include <queue>
#include <map>
#include <iostream>

using namespace std;

class Solution {
public:

	bool is_valid(vector<vector<char>>& mat,  int i, int j)
	{
		if(i >= 0 && i < 5 && j >= 0 && j< 5 && (mat[i][j] == '1') && (mat[i][j] != 'x'))
			return true;
		return false;
	}

	void bfs_count_islands(vector<vector<char>>& mat,  int i_new, int j_new) {

		queue<pair<int, int> > q;
		q.push(make_pair(i_new, j_new));
		while(q.size() > 0) {
			pair<int,int> p = q.front();
			int i = p.first;
			int j = p.second;
			q.pop();
			if(is_valid(mat, i, j))
			{
				mat[i][j] = 'x';
				q.push(make_pair(i - 1, j));
				q.push(make_pair(i, j - 1));
				q.push(make_pair(i + 1, j));
				q.push(make_pair(i, j + 1));
			}
		}
		return;
	}

	void dfs_count_islands(vector<vector<char>>& mat,  int i_new, int j_new) {

		if(! is_valid(mat, i_new, j_new))
			return;

	    //cout << "x=" << i_new << " " << "y=" << j_new << endl;
		mat[i_new][j_new] = 'x';
		dfs_count_islands(mat, i_new - 1, j_new);
		dfs_count_islands(mat, i_new, j_new - 1);
		dfs_count_islands(mat, i_new + 1, j_new);
		dfs_count_islands(mat, i_new, j_new + 1);
		return;
	}

    int numIslands(vector<vector<char>>& grid) {
    int count = 0;
	for (int i = 0; i < grid.size(); ++i)
	{
		for (int j = 0; j < grid[i].size(); ++j)
		{
			if (grid[i][j] == '1' && grid[i][j] != 'x')
			{
				count++;
				bfs_count_islands(grid, i , j);
			}
			/* code */
		}
		/* code */
	}
	return count;

    }
};


int main()
{
	vector<vector<char> > v{ {'1','1','1','1','0'}, {'1','1','0','1','0'}, {'1','1','0','0','0'}, {'0','0','0','0','0'}};
	Solution obj;
	cout << obj.numIslands(v) << endl;
}