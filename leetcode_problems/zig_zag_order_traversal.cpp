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

    vector<vector<int>> levelOrder1(TreeNode* root) {
        vector<vector<int>> ret;
        if (root == NULL)  return ret;   // NULL check

        // Create two stacks to store alternate levels
        stack<TreeNode*> s1;  // For levels to be printed from right to left
        stack<TreeNode*> s2;  // For levels to be printed from left to right

        // Push first level to first stack 's1'
        s1.push(root);

        // Keep ptinting while any of the stacks has some nodes
        while (!s1.empty() || !s2.empty())
        {
            // Print nodes of current level from s1 and push nodes of
            // next level to s2
            std::vector<int> v1;
            std::vector<int> v2;
            while (!s1.empty())
            {
                TreeNode *temp = s1.top();
                s1.pop();
                v1.push_back(temp->val);

                // Note that is right is pushed before left
                if (temp->right)
                    s2.push(temp->right);
                if (temp->left)
                    s2.push(temp->left);
            }
            ret.push_back(v1);
            // Print nodes of current level from s2 and push nodes of
            // next level to s1
            while (!s2.empty())
            {
                TreeNode *temp = s2.top();
                s2.pop();
                v2.push_back(temp->val);

                // Note that is left is pushed before right
                if (temp->left)
                    s1.push(temp->left);
                if (temp->right)
                    s1.push(temp->right);
            }
            ret.push_back(v2);
        }
        return ret;
    }

    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ret;
        if(root == NULL)
            return ret;
        queue<TreeNode *> q;
        q.push(root);
        bool toggle = true;
        int count = 1;
        while(q.size() > 0) {
            int children = 0;
            std::vector<int> tv;
            vector<TreeNode *> pv;
            while(count > 0) {
                count--;
                TreeNode* tmp = q.front();
                //cout << tmp->val << " ";
                pv.push_back(tmp);
                q.pop();
                if(tmp->left) {
                    q.push(tmp->left);
                    children++;
                }
                if(tmp->right) {
                    q.push(tmp->right);
                    children++;
                }
            }
            if(toggle) {
                for(int i = 0; i <pv.size(); i++) {
                    tv.push_back(pv[i]->val);
                    cout << pv[i]->val << " ";
                }
            }
            else {
                for(int i = pv.size() - 1; i >= 0; i--) {
                    tv.push_back(pv[i]->val);
                    cout << pv[i]->val << " ";
                }
            }

            toggle = !toggle;
            ret.push_back(tv);
            cout << endl;
            count = children;
        }
        return ret;
    }
vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    vector<vector<int>> res;
    if(!root) return res;
    std::deque<TreeNode*> deq;
    deq.push_back(root);
    int iszig=1;
    while(!deq.empty()) {
        int sz=deq.size();
        iszig=iszig^1;
        vector<int> row;
        while(sz--) {
            if(iszig) { // pop_front, push_back, right then left
                root=deq.front();deq.pop_front();
                row.push_back(root->val);
                if(root->right) deq.push_back(root->right);
                if(root->left) deq.push_back(root->left);
            }
            else { // pop_back, push_front, left then right
                root=deq.back();deq.pop_back();
                row.push_back(root->val);
                if(root->left) deq.push_front(root->left);
                if(root->right) deq.push_front(root->right);
            }
        }
        res.push_back(row);
    }
    return res;
}

};

int main()
{
    TreeNode *t = new TreeNode(1);
    t->left = new TreeNode(2);
    t->right = new TreeNode(3);
    t->left->left = new TreeNode(7);
    t->right->right = new TreeNode(4);
    t->right->left = new TreeNode(5);
    t->left->right = new TreeNode(6);
    Solution obj;
    //obj.levelOrder(t);
    for(auto &i : obj.zigzagLevelOrder(t)){
        for(auto &j : i){
    	   cout << j << " ";
        }
        cout << endl;
    }
}
