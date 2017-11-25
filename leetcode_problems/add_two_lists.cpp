#include <vector>
#include <queue>
#include <map>
#include <iostream>
#include <stack>
#include <list>

using namespace std;



struct ListNode {
	int val;
 	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* addTwoNumbers1(ListNode* l1, ListNode* l2) {
    	ListNode *head = NULL;
    	ListNode *curr = NULL;
    	ListNode *prev = NULL;
    	ListNode *pprev = NULL;
    	if(l1 == NULL)
    		return l2;
    	if(l2 == NULL)
    		return l1;
    	int carry = 0;
    	while(l1 != NULL || l2 != NULL) {
			int tmp  = carry + ((l1) ? l1->val : 0) + ((l2) ? l2->val : 0);
    		if (tmp >= 10){
    			carry = 1;
    			tmp = tmp % 10;
    		}
    		else{
    			carry = 0;
    		}
    		if (head == NULL)
    		{
    			head = new ListNode(tmp);
    			curr = head;
    		}
    		else {
    			curr = new ListNode(tmp);
    			prev->next = curr;
    		}
    		prev = curr;
    		pprev = prev;
    		if(l1)
    			l1 = l1->next;
    		if(l2)
    			l2 = l2->next;
    	}
		if(carry){
			pprev->next = new ListNode(1);
		}
    	return head;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *head = NULL;
        ListNode *prev = NULL;
        int carry = 0;
        while(l1 != NULL || l2 != NULL) {
            auto sum = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + carry;
            carry = sum > 10 ? 1 : 0;
            ListNode *temp = new ListNode(sum % 10);
            if(head == NULL)
                head = temp;
            else
                prev->next = temp;
            prev = temp;
            l1 = l1 ? l1->next : NULL;
            l2 = l2 ? l2->next : NULL;
        }
        if(carry) {
            prev->next = new ListNode(carry);
        }
        return head;
    }
};

int main()
{
	// ListNode *l1 = new ListNode(2);
	// l1->next = new ListNode(4);
	// l1->next->next = new ListNode(3);
	// ListNode *l2 = new ListNode(5);
	// l1->next = new ListNode(6);
	// l1->next->next = new ListNode(4);
	ListNode *l1 = new ListNode(1);
	l1->next = new ListNode(8);
	ListNode *l2 = new ListNode(0);
    Solution obj;
    ListNode *l3 = obj.addTwoNumbers(l1, l2);
    while(l3) {
    	cout << l3->val << endl;
    	l3 = l3->next;
    }

}