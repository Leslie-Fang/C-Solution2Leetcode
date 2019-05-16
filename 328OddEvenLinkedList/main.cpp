#include <iostream>
using namespace std;
 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
    	if(!head || !head->next)
    	{
    		return head;
    	}
    	ListNode* odd_start = head;
    	ListNode* even_start = head->next;
    	ListNode* cur_odd = head;
    	ListNode* cur_even = head->next;

		ListNode* pre = head->next;
    	ListNode* cur = head->next->next;
    	bool even = false;
    	while(cur)
    	{
    		// cout<<cur->val<<endl;
    		if(!even)
    		{
				cur_odd->next = cur;
				cur_odd = cur_odd->next;
				if(cur->next == NULL)
				{
					pre->next = NULL;
					break;
				}
				pre = cur;
				cur = cur->next;
				even = !even;
    		}else
    		{
    			cur_even->next = cur;
    			cur_even = cur_even->next;
    			pre = cur;
    			cur = cur->next;
    			even = !even;
    		}
    	}
    	// pre->next = NULL;
    	cur_odd->next = even_start;
    	// cout<<"<---------------------------------------->"<<endl;
    	// cur = head;
    	// while(cur)
    	// {
    	// 	cout<<cur->val<<endl;
    	// 	cur = cur->next;
    	// }
        return head;
    }
};
int main()
{
	Solution * mySolution = new Solution();
}