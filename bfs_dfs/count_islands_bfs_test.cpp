#include <iostream>
#include <queue>

using namespace std;

bool is_valid(int mat[][5],  int i, int j, int visited[][5])
{
	if(i >= 0 && i < 5 && j >= 0 && j< 5 && mat[i][j] && visited[i][j] != 1)
		return true;
	return false;
}

int bfs_count_islands(int mat[][5],  int i_new, int j_new, int visited[][5]) {

	queue<pair<int, int>> q;
	q.push(make_pair(i_new,j_new));

	while(q.size() > 0){
		pair<int,int> p = q.front();
		q.pop();
		int i = p.first;
		int j = p.second;
		if(is_valid(mat, i, j, visited)) {
			visited[i][j] = 1;
			q.push(make_pair(i - 1,j));
			q.push(make_pair(i , j -  1));
			q.push(make_pair(i + 1,j));
			q.push(make_pair(i, j + 1));
			q.push(make_pair(i + 1, j + 1));
		}
	}
	return 0;

}

int dfs_count_islands(int mat[][5],  int i_new, int j_new, int visited[][5]) {

	if(! is_valid(mat, i_new, j_new, visited))
		return 0;

	cout << "I=" << i_new << "J=" << j_new << endl;
	visited[i_new][j_new] = 1;
	dfs_count_islands(mat, i_new - 1, j_new, visited);
	dfs_count_islands(mat, i_new, j_new - 1, visited);
	dfs_count_islands(mat, i_new + 1, j_new, visited);
	dfs_count_islands(mat, i_new, j_new + 1, visited);
	//dfs_count_islands(mat, i_new + 1, j_new + 1, visited);
	return 0;
}


int main(int argc, char *argv[])
{
	int visited[5][5] = {
		{0,0,0,0,0},
		{0,0,0,0,0},
		{0,0,0,0,0},
		{0,0,0,0,0},
		{0,0,0,0,0},
	};

	int mat[5][5] = {
		{1,1,0,0,0},
		{0,1,0,0,0},
		{0,0,1,1,0},
		{1,1,1,0,0},
		{1,1,0,1,1},
	};

	int count = 0;
	for (int i = 0; i < 5; ++i)
	{
		for (int j = 0; j < 5; ++j)
		{
			if (mat[i][j] && visited[i][j] != 1)
			{
				count++;
				//bfs_count_islands(mat, i , j, visited);
				dfs_count_islands(mat, i , j, visited);
			}
			/* code */
		}
		/* code */
	}
	cout << count << endl;

	return 0;
}