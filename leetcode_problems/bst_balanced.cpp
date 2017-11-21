#include <vector>
#include <queue>
#include <map>
#include <iostream>
#include <stack>
#include <functional>
#include <unordered_map>
#include <set>


using namespace std;

struct TreeNode {
 	int val;
 	TreeNode *left;
 	TreeNode *right;
 	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
public:
	int isBalancedUtil(TreeNode *root) {
		if(root)
	}

    bool isBalanced(TreeNode* root) {
    	if(root) {
    		return abs(isBalancedUtil(root->left) - isBalancedUtil(root->right)) < 2;
    	}
    	return true;
};

int main()
{

    TreeNode *t = new TreeNode(3);
    t->left = new TreeNode(9);
    t->right = new TreeNode(20);
    t->right->left = new TreeNode(15);
    t->right->right = new TreeNode(9);
    t->right->right->right = new TreeNode(10);
    t->right->right->right->right = new TreeNode(11);

    //vector<vector<char> > v{{'X','O','X','O','X','O'},{'O','X','O','X','O','X'},{'X','O','X','O','X','O'},{'O','X','O','X','O','X'}};
    Solution obj;
    //obj.solve(v);
    cout << obj.isBalanced(t) << endl;
}