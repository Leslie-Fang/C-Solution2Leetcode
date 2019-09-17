#include<iostream>

using namespace std;
 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };
 
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* res, *prev, *cur, *temp, *temp2, *temp3;
        if(head == NULL || k==1)
        {
        	return head;
        }
        prev = head;
        cur = head->next;
        temp2 = head;

            for(int i=1;i<k;i++)
        	{
        		if(cur == NULL)
        		{
        			return head;
        		}
        		prev = cur;
        		cur = cur->next;
        	}
        prev = head;
        cur = head->next;

        for(int i=1;i<k;i++)
        {
        	temp = cur->next;
        	cur->next = prev;
        	prev = cur;
        	cur = temp;
        }
        res = prev;
        temp2->next = cur;
        if(cur == NULL)
        {
        	return res;
        }
        temp3 = temp2;
        while(1)
        {
        	prev = cur;
        	temp2 = cur;
        	if(cur->next)
        	{
        		cur = cur->next;
        	}else
        	{
        		return res;
        	}
        	for(int i=1;i<k;i++)
        	{
        		if(cur == NULL)
        		{
        			return res;
        		}
        		prev = cur;
        		cur = cur->next;
        	}
			temp3->next = prev;
			prev = temp2;
        	cur = prev->next;
        	
        	for(int i=1;i<k;i++)
	        {

	        	temp = cur->next;
	        	cur->next = prev;
	        	prev = cur;
	        	cur = temp;
	        }
	        temp2->next = cur;
	        if(cur == NULL)
	        {
	        	return res;
	        }
			
	        temp3 = temp2;


        }

        return res;
    }
};
int main(int argc, char ** argv)
{

}