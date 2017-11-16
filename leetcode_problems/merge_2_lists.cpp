#include <vector>
#include <queue>
#include <map>
#include <iostream>
#include <stack>
#include <functional>
#include <unordered_map>
#include <set>
#include <list>

using namespace std;


 struct ListNode {
 	int val;
 	ListNode *next;
 	ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    	ListNode head(INT_MIN);
    	ListNode *curr = &head;
    	while(l1 && l2){
    		if(l1->val < l2->val){
    			curr->next = l1;
    			l1 = l1->next;
    		}
    		else{
    			curr->next = l2;
    			l2 = l2->next;
    		}
    		curr = curr->next;
    	}
    	if(l1)
    		curr->next = l1;
    	if(l2)
    		curr->next = l2;
    	return head.next;
    }
};

int main()
{
    //vector<vector<char> > v{{'X','O','X','O','X','O'},{'O','X','O','X','O','X'},{'X','O','X','O','X','O'},{'O','X','O','X','O','X'}};
    Solution obj;
    //obj.solve(v);
    ListNode *l1 = new ListNode(1);
    l1->next = new ListNode(5);
    l1->next->next = new ListNode(7);
    l1->next->next->next = new ListNode(8);

    ListNode *l2 = new ListNode(2);
    l2->next = new ListNode(3);
    l2->next->next = new ListNode(4);
    l2->next->next->next = new ListNode(4);

    ListNode *l3 =  obj.mergeTwoLists(l1, l2);
    while(l3){
   		cout << l3->val << endl;
   		l3 = l3->next;
    }
}