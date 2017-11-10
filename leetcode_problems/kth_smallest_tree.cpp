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
    int kthSmallest(TreeNode* root, int& k) {
    	if(root){
    		int x = kthSmallest(root->left, k);
    		if(k == 0)
    			return x;
            k--;
            if(k == 0)
                return root->val;
    		return kthSmallest(root->right, k);
    	}
    	return INT_MIN;

    }

};





int main()
{
    TreeNode *t = new TreeNode(2);
    t->left = new TreeNode(1);
    Solution obj;
    //obj.solve(v);
    int k = 1;
    cout << obj.kthSmallest(t, k) << endl;
}