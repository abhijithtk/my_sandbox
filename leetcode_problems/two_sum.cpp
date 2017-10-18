#include <vector>
#include <queue>
#include <map>
#include <iostream>

using namespace std;


class Solution {
public:
    int solve(vector<int>& board) {
    	int target  = 18;
    	map<int, int> m;
    	for (int i = 0; i < board.size(); i++) {
    		int diff = target - board[i];
    		if(m.find(diff) != m.end()) {
    			cout << "Found" << diff << " at " << m[diff] << " and found " << board[i] << "at" << i << endl;
    			break;
    		}
    		cout << i << endl;
    		m.insert(make_pair(board[i],i));

    	}
    	return 1;
    }
};

int main()
{
    vector<int> v{18, 7, 11, 4, 16, 22, 15};
    Solution obj;
    //obj.solve(v);
    cout << obj.solve(v) << endl;
}