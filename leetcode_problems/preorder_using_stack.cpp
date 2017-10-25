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
    	TreeNode *p = root;;
        while(!s.empty() || p != NULL) {
            if(p != NULL) {
                s.push(p);
                //v.insert(v.begin(), p->val);
                //v.push_back(p->val);  // Reverse the process of preorder
                //p = p->right;             // Reverse the process of preorder
                p = p->left;             // Reverse the process of preorder
            } else {

                TreeNode *node = s.top();
                v.push_back(node->val);  // Reverse the process of preorder
                s.pop();
                //p = node->left;           // Reverse the process of preorder
                p = node->right;           // Reverse the process of preorder
            }
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