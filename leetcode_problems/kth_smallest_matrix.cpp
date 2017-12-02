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

class Functor {
	public:
		bool operator()(pair<int, pair<int,int>> &p1, pair<int, pair<int,int>> &p2) {
			return p1.first > p2.first;
		}
};

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
    	priority_queue<pair<int, pair<int,int>>, vector<pair<int, pair<int,int>>>, Functor> pq;
    	for (int i = 0; i < matrix[0].size(); ++i)
    	{
    		pq.push({matrix[0][i], {0,i}});
    	}
    	int val = 0;
    	int next = 0;
    	for(int i = 0; i < k; i++) {
    		pair<int, pair<int,int>> p = pq.top();
    		pq.pop();
    		val = p.first;
    		int row = p.second.first;
    		int col = p.second.second;
    		cout << val << " " << row << " " << col <<  " " << endl;
    		next  = INT_MAX;
    		if(row + 1 >= matrix.size())
    			next = INT_MAX;
    		else
    			next = matrix[row + 1][col];
    		pq.push({next,{row + 1, col}});
    		cout << "N=" << next << endl;
    	}
    	return val;
    }
};

int main()
{
    vector<vector<int> > matrix{
	{ 1,  5,  9},
   {10, 11, 14},
   {12, 13, 15}
};
    Solution obj;
    //obj.solve(v);
    cout << obj.kthSmallest(matrix, 8) << endl;
}