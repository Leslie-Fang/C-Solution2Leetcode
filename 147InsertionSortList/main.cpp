#include <iostream>
using namespace std;

 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };
 
class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
    	if(!head)
    	{
    		return head;
    	}
    	ListNode* cur = head;
        ListNode* res = new ListNode(head->val);
        ListNode* temp = NULL;
        ListNode* temp2 = NULL;
        ListNode* pre = NULL;
        while(cur->next)
        {
        	cur = cur->next;
        	if(cur->val < res->val)
        	{
        		temp = res;
        		res = new ListNode(cur->val);
        		res->next = temp;
        		continue;
        	}
        	temp = res->next;
        	pre = res;
        	while(temp)
        	{
        		if(cur->val < temp->val)
        		{
        			break;
        		}
        		pre = temp;
        		temp = temp->next;
        	}
        	if(temp)
        	{
        		temp2 = new ListNode(cur->val);
        		pre->next = temp2;
        		temp2->next = temp;
        	}else
        	{
        		temp2 = new ListNode(cur->val);
        		pre->next = temp2;
        	}
        }
        return res;
    }
};

int main(int argc, char ** argv){
	Solution * mySolution = new Solution();

	delete mySolution;
	return 1;
}