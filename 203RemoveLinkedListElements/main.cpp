#include <iostream>

using namespace std;

 struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
    	if(!head)
    	{
    		return head;
    	}
        ListNode * cur = head;
        ListNode * pre = NULL;
        while(cur)
        {
        	if(cur->val == val)
        	{
        		if(pre)
        		{
        			pre->next = cur->next;
        			cur = cur->next;
        		}else
        		{
        			head = head->next;
        			cur = head;
        			pre = NULL;
        		}
        	}else
        	{
        		pre = cur;
        		cur = cur->next;
        	}
        }
        return head;
    }
};

int main()
{
	cout<<"Hello"<<endl;
	return 0;
}