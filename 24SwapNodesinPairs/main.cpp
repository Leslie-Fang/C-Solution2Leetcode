#include <iostream>
using namespace std;
 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
    	ListNode* temp;
    	ListNode* res;
    	ListNode* prev;
    	ListNode* first;
    	ListNode* second;
    	if(!head)
    	{
    		return head;
    	}
    	if(head->next)
    	{
    		res = head->next;
    		temp = head->next->next;
    		res->next = head;
    		res->next->next = temp;
    		prev = res->next;
    		first = prev->next;
    		if(first)
    		{
    			second = first->next;
    		}else
    		{
    			return res;
    		}
    	}else
    	{
    		return head;
    	}
    	while(first)
    	{
    		if(second)
    		{
    			temp = second->next;
    			prev->next = second;
    			second->next = first;
    			first->next = temp;
    			prev = first;
    			first = prev->next;
    			if(first)
    			{
    				second = first->next;
    			}
    		}else
    		{
    			break;
    		}

    	}
    	return res;
        
    }
};
int main(int argc, char ** argv)
{
	return 1;
}