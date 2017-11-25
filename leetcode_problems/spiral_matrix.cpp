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
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
   		std::vector<int> v;
   		if(matrix.size() == 0)
   			return v;
   		int r1 = 0;
   		int c1 = 0;
   		int r2 = matrix.size() -1;
   		int c2 = matrix[0].size() - 1;
   		while(r1 <= r2 && c1 <= c2) {
   			for(int c = c1; c <= c2; c++) {
   				v.push_back(matrix[r1][c]);
   			}
			for(int r = r1 + 1; r <= r2; r++) {
				v.push_back(matrix[r][c2]);
			}
			if(c1 < c2 && r1 < r2) {
				for(int c = c2 - 1; c > c1; c--) {
					v.push_back(matrix[r2][c]);
				}
				for(int r = r2; r > r1; r--) {
					v.push_back(matrix[r][c1]);
				}
			}
			r1++;
			r2--;
			c1++;
			c2--;
   		}
   		return v;
    }
};

int main()
{
	vector<vector<int> > v{
 { 1, 2, 3 },
 { 8, 9, 4 },
 { 7, 6, 5 }
};
    Solution obj;
    //obj.solve(v);
    for(auto i : obj.spiralOrder(v))  {
    	cout << i << endl;
    }
}