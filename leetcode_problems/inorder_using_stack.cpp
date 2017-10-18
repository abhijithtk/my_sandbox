#include <vector>
#include <queue>
#include <map>
#include <iostream>
#include <stack>

using namespace std;



struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
    	std::vector<int> v;
    	stack<TreeNode*> s;
    	TreeNode *cur = root;
    	while(cur != NULL || ! s.empty()) {
    		while(cur != NULL) {
    			s.push(cur);
    			cur = cur->left;
    		}
    		cur = s.top();
    		s.pop();
    		v.push_back(cur->val);
    		cur = cur->right;
    	}
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
    t->right->left = new TreeNode(6);
    Solution obj;
    for(auto &i : obj.inorderTraversal(t))
    	cout << i << endl;
}