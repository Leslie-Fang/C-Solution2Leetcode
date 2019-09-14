#include <iostream>
using namespace std;
 struct ListNode {
     int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* res = new ListNode(1);
        ListNode* temp[n+1];
        temp[0] = head;
        for(int i=1;i<n+1;i++)
        {
        	if(temp[i-1]->next)
        	{
        		temp[i] = temp[i-1]->next;
        	}else
        	{
        		return head->next;
        	}
        }
        while(1)
        {
        	if(temp[n]->next)
        	{
        		for(int i=0;i<n+1;i++)
		        {
		        	temp[i] = temp[i]->next;
		        }
        	}else
        	{
        		if(n>=2)
        		{
        			temp[0]->next=temp[2];
        		}else
        		{
        			temp[0]->next = NULL;
        		}
        		break;
        	}
        }
        return head;
    }
};

int main(int argc, char ** argv)
{
	ListNode* head = new ListNode(1);
	Solution * mySolution = new Solution();
	mySolution->removeNthFromEnd(head,1);
	delete mySolution;
}