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
	ListNode *l1 = new ListNode(4);
	l1->next = new ListNode(1);
	l1->next->next = new ListNode(2);
	ListNode *l2 = new ListNode(7);
	l2->next = new ListNode(1);
	l2->next->next = new ListNode(9);
	// ListNode *l1 = new ListNode(1);
	// l1->next = new ListNode(8);
	// ListNode *l2 = new ListNode(0);
    Solution obj;
    ListNode *l3 = obj.addTwoNumbers(l1, l2);
    while(l3) {
    	cout << l3->val << endl;
    	l3 = l3->next;
    }

}