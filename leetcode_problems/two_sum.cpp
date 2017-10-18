#include <vector>
#include <queue>
#include <map>
#include <iostream>

using namespace std;


class Solution {
public:
    vector<int> solve(vector<int>& board) {
    	int target  = 9;
    	vector<int> v;
    	map<int, int> m;
    	for (int i = 0; i < board.size(); i++) {
    		int diff = target - board[i];
    		if(m.find(diff) != m.end()) {
    			v.push_back(m[diff]);
    			v.push_back(i);
    			//cout << "Found" << diff << " at " << m[diff] << " and found " << board[i] << "at" << i << endl;
    			break;
    		}
    		//cout << i << endl;
    		m.insert(make_pair(board[i],i));

    	}
    	return v;
    }
};

int main()
{
    vector<int> v{2, 7, 11, 15};
    Solution obj;
    //obj.solve(v);
    //cout << obj.solve(v) << endl;
    for(auto &i : obj.solve(v))
    	cout << i << endl;
}