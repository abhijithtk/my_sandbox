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

struct TreeNode {
 	int val;
 	TreeNode *left;
 	TreeNode *right;
 	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
public:
	// For each node, get
	int solve(TreeNode *root,vector<std::vector<int> > &res ) {
		if(root == NULL)
			return -1;
		int l = solve(root->left, res);
		int r = solve(root->right, res);
		int cur = max(l,r) + 1;

		if(res.size() <= cur) {
			res.push_back(std::vector<int>());
		}
		res[cur].push_back(root->val);
		return cur;

	}

    vector<std::vector<int> > solve(TreeNode *root) {
    	std::vector<std::vector<int> > v;
    	solve(root, v);
    	return v;

    }
};

int main()
{
    TreeNode *t = new TreeNode(1);
    t->left = new TreeNode(2);
    t->right = new TreeNode(3);
    t->left->left = new TreeNode(4);
    t->left->right = new TreeNode(5);

    //vector<vector<char> > v{{'X','O','X','O','X','O'},{'O','X','O','X','O','X'},{'X','O','X','O','X','O'},{'O','X','O','X','O','X'}};
    Solution obj;
    for(auto i: obj.solve(t)){
    	for(auto j : i) {
    		cout << j << " ";
    	}
		cout << endl;
    }
    //cout << obj.solve(v) << endl;
}