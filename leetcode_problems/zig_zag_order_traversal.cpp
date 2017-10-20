#include <vector>
#include <queue>
#include <map>
#include <iostream>

using namespace std;


struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };


class Solution {
public:
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
};

int main()
{
    TreeNode *t = new TreeNode(1);
    t->left = new TreeNode(2);
    t->right = new TreeNode(3);
    t->left->left = new TreeNode(4);
    t->right->right = new TreeNode(5);
    //t->right->left = new TreeNode(6);
    Solution obj;
    obj.levelOrder(t);
    //for(auto &i : obj.levelOrder(t))
    //	cout << i << endl;
}
