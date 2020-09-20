#include <iostream>
using namespace std;

 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
 
class Solution {
public:
	ListNode* reverseList(ListNode* root, int & length){
		ListNode* prev = nullptr;
		ListNode* cur = root;
		ListNode* next = root->next;
		//ListNode* res = nullptr;
		while(cur){
			next = cur->next;
			cur->next = prev;
			prev = cur;
			cur = next;
			length += 1;
		}
		return prev;
	}

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
       ListNode* res;
       ListNode* prev = nullptr;
       ListNode* res_tmp = nullptr;
       //unique_ptr<ListNode> res;
       //unique_ptr<ListNode>
       int l1_length = 0;
       int l2_length = 0;

       ListNode* l1v = reverseList(l1, l1_length);
       ListNode* l2v = reverseList(l2, l2_length);
       ListNode* temp1 = l1v;
       ListNode* temp2 = l2v;
       bool overflow = false;
       //int val = 0;

       //ListNode* to_use = nullptr;
       if(l1_length >= l2_length){
       	 res_tmp = l1v;
         temp1 = l1v;
         temp2 = l2v;
       }else{
       	 res_tmp = l2v;
       	 temp1 = l2v;
       	 temp2 = l1v;
       }

       while(temp1 && temp2){
       	temp1->val += temp2->val;
       	if(overflow){
       		temp1->val += 1;
       	}
       	if(temp1->val>=10){
       		overflow = true;
       		temp1->val = temp1->val - 10;
       	}else{
       		overflow = false;
       	}
       	//temp1->val = val;
       	prev = temp1;
       	temp1 = temp1->next;
       	temp2 = temp2->next;
       }
       if(l1_length == l2_length){
       	if(overflow){
       		ListNode * newNode = new ListNode(1);
       		prev->next = newNode;
       	}
       }else{
       	if(overflow){
       		temp1->val += 1;
       		while(temp1->val >= 10){
       			temp1->val -= 10;
       			if(!temp1->next){
       				ListNode * newNode = new ListNode(1);
       				temp1->next = newNode;
       				break;
       			}
       			temp1 = temp1->next;
       			temp1->val += 1;
       		}
       	}
       }
       int dummy = 0;
       res = reverseList(res_tmp, dummy);

       //return res.get(); 
       return res;
    }
};

int main(int argc, char ** argv){

	return 0;
}