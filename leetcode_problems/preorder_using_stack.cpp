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
    vector<int> preorderTraversal(TreeNode* root) {
        std::vector<int> res;
        if(!root)
            return res;
        stack<TreeNode *> s;
        s.push(root);
        while(!s.empty()) {
            TreeNode *temp =  s.top();
            s.pop();
            res.push_back(temp->val);
            if(temp->right)
                s.push(temp->right);
            if(temp->left)
                s.push(temp->left);
        }
        return res;
    }

    // This is the reverse of N L R
    // Do N R L below. reverse it, to get L R N
    vector<int> postorderTraversal(TreeNode* root) {
        std::vector<int> res;
        if(!root)
            return res;
        stack<TreeNode *> s;
        s.push(root);
        while(!s.empty()) {
            TreeNode *temp =  s.top();
            s.pop();

            res.push_back(temp->val);
            if(temp->left)
                s.push(temp->left);
            if(temp->right)
                s.push(temp->right);
        }
        reverse(res.begin(), res.end());
        return res;
    }
    // vector<int> inorderTraversal1(TreeNode* root) {
    // 	std::vector<int> v;
    // 	stack<TreeNode*> s;
    // 	TreeNode *p = root;;
    //     while(!s.empty() || p != NULL) {
    //         if(p != NULL) {
    //             s.push(p);
    //             //v.insert(v.begin(), p->val);
    //             //v.push_back(p->val);  // Reverse the process of preorder
    //             //p = p->right;             // Reverse the process of preorder
    //             p = p->left;             // Reverse the process of preorder
    //         } else {

    //             TreeNode *node = s.top();
    //             v.push_back(node->val);  // Reverse the process of preorder
    //             s.pop();
    //             //p = node->left;           // Reverse the process of preorder
    //             p = node->right;           // Reverse the process of preorder
    //         }
    //     }
    // 	return v;
    // }
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
    for(auto &i : obj.postorderTraversal(t))
    	cout << i << endl;
}