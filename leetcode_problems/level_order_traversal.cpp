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
    vector<vector<int>> zigzagOrder(TreeNode* root) {
        vector<vector<int>> ret;
        if(root == NULL)
            return ret;
        deque<TreeNode *> dq;
        dq.push_back(root);
        int count = 1;
        while(dq.size() > 0) {
            int children = 0;
            std::vector<int> tv;
            while(count > 0) {
                count--;
                TreeNode* tmp = dq.front();
                cout << tmp->val << " ";
                tv.push_back(tmp->val);
                dq.pop_back();
                if(tmp->left) {
                    dq.push_front(tmp->left);
                    children++;
                }
                if(tmp->right) {
                    dq.push_front(tmp->right);
                    children++;
                }
            }
            ret.push_back(tv);
            cout << endl;
            count = children;
        }
        return ret;
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ret;
        if(root == NULL)
            return ret;
    	queue<TreeNode *> q;
    	q.push(root);
    	int count = 1;
    	while(q.size() > 0) {
    		int children = 0;
    		std::vector<int> tv;
    		while(count > 0) {
    			count--;
    			TreeNode* tmp = q.front();
    			cout << tmp->val << " ";
    			tv.push_back(tmp->val);
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
    		ret.push_back(tv);
    		cout << endl;
    		count = children;
    	}
    	return ret;
    }
};

int main()
{
    TreeNode *t = new TreeNode(3);
    t->left = new TreeNode(9);
    t->right = new TreeNode(20);
    t->right->left = new TreeNode(15);
    t->right->right = new TreeNode(7);
    //t->right->left = new TreeNode(6);
    Solution obj;
    obj.levelOrder(t);
    obj.zigzagOrder(t);
    //for(auto &i : obj.levelOrder(t))
    //	cout << i << endl;
}
