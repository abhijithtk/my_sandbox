#include <vector>
#include <queue>
#include <map>
#include <iostream>
#include <stack>
#include <unordered_set>

using namespace std;


class Solution {
public:
	bool isValidRow(vector<vector<char>>& board, int row){
		map<char,int> m;
		for(int i = 0; i< 9; i++)
		{
			if(board[row][i] == '.')
				continue;

			if( m.find(board[row][i]) == m.end() ){
				m.insert(make_pair(board[row][i],1));
			}
			else {
				return false;
			}
		}
		return true;
	}
	bool isValidCol(vector<vector<char>>& board, int col){
		map<char,int> m;
		for(int i = 0; i< 9; i++)
		{
			if(board[i][col] == '.')
				continue;
			if(m.find(board[i][col]) == m.end()){
				m.insert(make_pair(board[i][col],1));
			}
			else
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

	bool isValidSquare(vector<vector<char>>& board, int row, int col){
		int i = getSt(row);
		int j = getSt(col);
		for(int a = i; a < (i + 3); a++){
			for(int b = j; b < (j + 3); b++){
				if(board[a][b] == board[row][col] && a != row && b != col)
					return false;
			}
		}
		return true;
	}

    bool isValidSudoku1(vector<vector<char>>& board) {
    	for(int i = 0; i < 9; i++){
    		for(int j = 0; j< 9; j++){
    			if(board[i][j] == '.')
    				continue;
    			if(! isValidRow(board, i) || ! isValidCol(board, j) || ! isValidSquare(board, i, j))
    				return false;
    		}
    	}
    	return true;
    }
	bool isValidSudokuAbhiTest(vector<vector<char>>& board) {
	    unordered_set<string> seen;
	    for(int i = 0; i < 9; i++) {
	    	for(int j = 0; j < 9; j++) {
	    		string val = "{" + (to_string(board[i][j] - '0')) + "}";
	    		string row = val + to_string(i);
	    		string col = to_string(j) + val;
	    		string square = to_string(j) + val + to_string(i);
	    		if(seen.find(row) == seen.end() || seen.find(col) == seen.end() || seen.find(square) == seen.end()) {
	    			return false;
	    		}
	    		else {
	    			seen.insert(row);
	    			seen.insert(col);
	    			seen.insert(square);
	    		}
	    	}
	    }
	    return true;
	}
	bool isValidSudoku(vector<vector<char>>& board) {
	    unordered_set<string> seen;
	    for (int i=0; i<9; ++i) {
	        for (int j=0; j<9; ++j) {
	            if (board[i][j] != '.') {
	                string b = "(" + to_string(board[i][j] - '0') + ")";
	                string row = b + to_string(i);
	                string col = to_string(j) + b;
	                string square = to_string(i/3) + b + to_string(j/3);
	                cout << row << " " << col << " " << square << endl;
	                if (seen.find(row) != seen.end() || seen.find(col) != seen.end() || seen.find(square) != seen.end())
	                    return false;
	                else {
	                	seen.insert(row);
	                	seen.insert(col);
	                	seen.insert(square);
	                }
	            }
	        }
	    }
	    return true;
	}
};


int main()
{
    vector<vector<char> > v{
    	{'.','8','7','6','5','4','3','2','1'} ,
    	{'2','.','.','.','.','.','.','.','.'} ,
    	{'3','1','.','.','.','.','.','.','.'} ,
    	{'4','.','.','.','.','.','.','.','.'} ,
    	{'5','.','.','.','.','.','.','.','.'} ,
    	{'6','.','.','.','.','.','.','.','.'} ,
    	{'7','.','.','.','.','.','.','.','.'} ,
    	{'8','.','.','.','.','.','.','.','.'} ,
    	{'9','.','.','.','.','.','.','.','7'}};
    Solution obj;
    //obj.solve(v);
    cout << obj.isValidSudoku(v) << endl;
}