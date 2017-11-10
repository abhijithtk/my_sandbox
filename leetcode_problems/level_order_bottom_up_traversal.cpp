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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> ret;
        if(root == NULL)
            return ret;

        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            std::vector<int> v;
            for(int i = 0; i < size; i++){
                TreeNode *tmp = q.front();
                q.pop();
                v.push_back(tmp->val);
                if(tmp->left)
                    q.push(tmp->left);
                if(tmp->right)
                    q.push(tmp->right);
            }
            ret.push_back(v);
        }
        reverse(ret.begin(),ret.end());
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
    for(auto &i : obj.levelOrderBottom(t)){
        for(auto &j: i){
            cout << " " << j;
        }
        cout << endl;
    }
}
