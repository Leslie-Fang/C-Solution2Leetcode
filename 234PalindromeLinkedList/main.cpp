#include <iostream>

using namespace std;
 struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
 
class Solution {
public:
    bool isPalindrome(ListNode* head) {
    	if(head != NULL)
    	{
    		//Step1.利用快慢指针，找到链表的中点
    		ListNode* slow = head;
    		ListNode* quick = head;
    		ListNode* last = head;
    		//ListNode* quick_last = head;
    		while(quick != NULL && quick->next !=NULL)
    		{
    			last = slow;
    			slow = slow->next;
    			//quick_last = quick;
    			quick = quick->next->next;
    		}
    		bool even_num = false;
    		if(!quick)
    		{
    			//偶数个节点
    			even_num = true;
    			//quick_last = quick_last->next;

    		}else if(!quick->next)
    		{
    			//奇数个节点
    			even_num = false;
    			//quick_last = quick;
    		}else
    		{
    			cout<<"Error logic"<<endl;
    		}

    		ListNode* mid_head = NULL;
	    	//Step2.从中间断开链表
    		if(even_num)
    		{
    			//偶数个节点
    			mid_head = slow;
    			last->next = NULL;
    		}else
    		{
    			//奇数个节点
    			mid_head = slow->next;
    			last->next = NULL;
    			slow->next = NULL;
    		}
    		//Step3. 就地反转链表的后半段
    		ListNode* temp = NULL;
    		last = NULL;
    		ListNode* cur = mid_head;
    		while(cur)
    		{
    			temp = cur->next;
    			cur->next = last;
    			last = cur;
    			cur = temp;
    		}
    		mid_head = last;
	    	//Step4.判断这两个链表是否相等
	    	temp = head;
	    	ListNode* temp2 = mid_head;
	    	while(temp && temp2)
	    	{
	    		if(temp->val != temp2->val)
	    		{
	    			return false;
	    		}
	    		temp = temp->next;
	    		temp2 = temp2->next;
	    	}

    	}
    	return true;        
    }
};

int main(int argc, char ** argv)
{

}