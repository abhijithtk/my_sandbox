#include <vector>
#include <queue>
#include <map>
#include <iostream>

using namespace std;


class Solution {
public:
	bool is_valid(vector<vector<int>>& mat,  int i, int j)
	{
		if(i >= 0 && i < mat.size() && j >= 0 && j< mat[i].size() && (mat[i][j] == 1) && (mat[i][j] != 9))
			return true;
		return false;
	}

	void bfs_count_islands(vector<vector<int>>& mat,  int i_new, int j_new) {

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

	int dfs_count_islands(vector<vector<int>>& mat,  int i_new, int j_new) {

		if(! is_valid(mat, i_new, j_new))
			return 0;

		int c = 1;
	    //cout << "x=" << i_new << " " << "y=" << j_new << endl;
		mat[i_new][j_new] = 9;
		c+= dfs_count_islands(mat, i_new - 1, j_new);
		c+= dfs_count_islands(mat, i_new, j_new - 1);
		c+= dfs_count_islands(mat, i_new + 1, j_new);
		c+= dfs_count_islands(mat, i_new, j_new + 1);
		return c;
	}

    int maxAreaOfIsland(vector<vector<int>>& grid) {
		int max = 0;
	    int count = 0;
		for (int i = 0; i < grid.size(); ++i)
		{
			for (int j = 0; j < grid[i].size(); ++j)
			{
				if (grid[i][j] == 1 && grid[i][j] != 9)
				{
					count = dfs_count_islands(grid, i , j);
					max = max > count ? max : count;
				}
				/* code */
			}
			/* code */
		}
		return max;
	}
};

int main()
{
	vector<vector<int> > v{ {1,1,0,0,0},{1,1,0,0,0},{0,0,0,1,1},{0,0,0,1,1}};
	Solution obj;
	cout << obj.maxAreaOfIsland(v) << endl;
}