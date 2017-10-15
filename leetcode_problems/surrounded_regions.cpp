#include <vector>
#include <queue>
#include <map>
#include <iostream>

using namespace std;

using namespace std;

class Solution {
public:
	bool is_valid(vector<vector<char>>& board, int i, int j) {
		if(i >= 0 && i < board.size() && j >= 0 && j < board[0].size() && board[i][j] == 'O') {
			board[i][j] = 'B';
			return true;
		}
		return false;
	}
	void bfs(vector<vector<char>>& board, int i, int j) {
		queue<pair<int, int>> q;
		q.push(make_pair(i,j));
		while(q.size() > 0) {
			pair<int,int> p = q.front();
			q.pop();
			int i_new = p.first;
			int j_new = p.second;
			if(is_valid(board, i_new, j_new)) {
				q.push(make_pair(i_new -1, j_new));
				q.push(make_pair(i_new, j_new - 1));
				q.push(make_pair(i_new + 1, j_new));
				q.push(make_pair(i_new , j_new + 1));
			}
		}
	}

    void solve(vector<vector<char>>& board) {
    	int l = board.size();
    	if (l == 0)
    		return;
    	int b = board[0].size();
    	if (b == 0)
    		return;
    	for(int i = 0; i < l; i++) {
    		if(board[i][0] == 'O')
    			bfs(board, i , 0);

    		if(board[i][b -1] == 'O')
    			bfs(board, i, b - 1);
    	}

    	for(int j = 0; j < b; j++) {
    		if(board[0][j] == 'O')
    			bfs(board, 0 , j);
    		if(board[l - 1][j] == 'O')
    			bfs(board, l - 1, j);
    	}
    	for(int i = 0; i < l; i++) {
    		for(int j = 0; j < b; j++) {
    			if(board[i][j] == 'O')
    				board[i][j] = 'X';
    			if(board[i][j] == 'B')
    				board[i][j] = 'O';
			}
    	}
    }
};

int main()
{
	vector<vector<char> > v{{'X','O','X','O','X','O'},{'O','X','O','X','O','X'},{'X','O','X','O','X','O'},{'O','X','O','X','O','X'}};
	Solution obj;
	obj.solve(v);
	//cout << obj.solve(v) << endl;
}