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
	void printMat(vector<vector<int>>& matrix) {
		for(auto i : matrix){
			for( auto j : i) {
				cout << " " << j;
			}
			cout << endl;
		}
	}
	// m + n solution
    void setZeroes1(vector<vector<int>>& matrix) {
    	printMat(matrix);
    	vector<int> r;
    	std::vector<int> c;
    	int m = matrix.size();
    	int n = m > 0 ? matrix[0].size() : 0;
    	bool found = false;
        for(int i = 0; i < matrix.size(); i++){
        	for(int j = 0; j < matrix[i].size(); j++) {
        		if(matrix[i][j] == 0) {
        			r.push_back(i);
        			c.push_back(j);
        		}
        	}
        }
        for(int i = 0; i < r.size(); i++){
        	for(int j = 0; j < n; j++)
        		matrix[r[i]][j] = 0;
        }
        for(int i = 0; i < c.size(); i++){
        	for(int j = 0; j < m; j++)
        		matrix[j][c[i]] = 0;
        }
        printMat(matrix);
    }

    void setZeroes(vector<vector<int>>& matrix) {
    	printMat(matrix);
    	bool row = false;
    	bool col = false;
    	int l = 0, r = 0, t = 0, d = 0;
        for(int i = 0; i < matrix.size(); i++){
        	for(int j = 0; j < matrix[i].size(); j++) {
        		if(matrix[i][j] == 0) {
        			matrix[i][0] = 0;
        			matrix[0][j] = 0;
        			if(i == 0)
        				row = true;
        			if(j == 0)
        				col = true;
        		}
        	}
        }
        printMat(matrix);
        for(int i = 1; i < matrix.size(); i++){
            for(int j = 1; j < matrix[0].size(); j++){
                if(matrix[i][0] == 0 || matrix[0][j] == 0) matrix[i][j] = 0;
            }
        }
        if(col){
            for(int i = 0; i < matrix.size(); i++) matrix[i][0] = 0;
        }
        if(row){
            for(int j = 0; j < matrix[0].size(); j++) matrix[0][j] = 0;
        }
        printMat(matrix);
    }
};


int main()
{
    vector<vector<int> > v{{1,1,1,0,1,1},{1,1,1,1,1,1},{1,1,1,1,1,1},{1,1,1,1,1,1}};
    Solution obj;
    obj.setZeroes(v);
    //cout << obj.setZeroes(v) << endl;
}