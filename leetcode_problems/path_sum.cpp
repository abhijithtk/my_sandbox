/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> res;
    void pathSum(TreeNode* root, int sum, vector<int> &v) {
        if(!root)
            return;
        v.push_back(root->val);
        if(root->val == sum && !root->left && !root->right)
            res.push_back(v);
        pathSum(root->left, sum - root->val, v);
        pathSum(root->right, sum - root->val, v);
        v.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<int> path;
        pathSum(root, sum, path);
        return res;
    }
};

class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if(root == NULL) return false;
        if (root->val == sum && root->left == NULL && root->right == NULL) return true;
        return hasPathSum(root->left, sum - root->val) || hasPathSum(root->right, sum - root->val);
    }
};

// sum is only with leaf nodes
