#include <vector>
#include <queue>
#include <map>
#include <iostream>

using namespace std;

class Solution {
public:
    void solve(vector<vector<char>>& board) {

    }
};

int main()
{
	vector<vector<char> > v{ {'1','1','1','1','0'}, {'1','1','0','1','0'}, {'1','1','0','0','0'}, {'0','0','0','0','0'}};
	Solution obj;
	cout << obj.solve(v) << endl;
}