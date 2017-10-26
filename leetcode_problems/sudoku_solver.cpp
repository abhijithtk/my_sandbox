


#include <vector>
#include <queue>
#include <map>
#include <iostream>
#include <stack>

using namespace std;


class Solution {
public:
	bool isValidRow(vector<vector<char>>& board, int row, char k){
		for(int i = 0; i< 9; i++)
		{
			if(board[row][i] == k)
				return false;
		}
		return true;
	}

	bool isValidCol(vector<vector<char>>& board, int col, char k){
		for(int i = 0; i< 9; i++)
		{
			if(board[i][col] == k)
				return false;
		}
		return true;
	}

	int getSt(int index) {
		if(index < 3)
			return 0;
		else if(index >= 3 && index < 6)
			return 3;
		else if(index >= 6 && index < 9)
			return 6;
		else
			return -1;
	}

	bool isValidSquare(vector<vector<char>>& board, int row, int col, char k){
		int i = getSt(row);
		int j = getSt(col);
		for(int a = i; a < (i + 3); a++){
			for(int b = j; b < (j + 3); b++){
				if(board[a][b] == k)
					return false;
			}
		}
		return true;
	}

    bool solveSudokuHelper(vector<vector<char>>& board, int i, int j) {
    	for(int i = 0; i < 9; i++){
    		for(int j = 0; j< 9; j++){
    			if(board[i][j] == '.') {
    				for(char k = '1'; k <= '9'; k++){
						if(isValidRow(board, i, k) && isValidCol(board, j, k) && isValidSquare(board, i, j, k)) {
							board[i][j] = k;
	    					if( solveSudokuHelper(board, i , j)) {
	    						return true;
	    					}
	    					else {
	    						board[i][j] = '.';
	    					}
    					}
    				}
					return false;
    			}
    		}
    	}
		return true;
	}

    void solveSudoku(vector<vector<char>>& board) {
    	solveSudokuHelper(board, 0, 0);
    }
};


int main()
{
    vector<vector<char> > v{
    	{'.','.','9','7','4','8','.','.','.'},
    	{'7','.','.','.','.','.','.','.','.'},
    	{'.','2','.','1','.','9','.','.','.'},
    	{'.','.','7','.','.','.','2','4','.'},
    	{'.','6','4','.','1','.','5','9','.'},
    	{'.','9','8','.','.','.','3','.','.'},
    	{'.','.','.','8','.','3','.','2','.'},
    	{'.','.','.','.','.','.','.','.','6'},
    	{'.','.','.','2','7','5','9','.','.'}};
    Solution obj;
    obj.solveSudoku(v);
    for(int i = 0; i < v.size(); i++){
    	for(int j = 0;  j< v[i].size(); j++) {
    		cout << v[i][j] << " ";
    	}
    	cout << endl;
    }
    //cout << obj.solveSudoku(v) << endl;
}