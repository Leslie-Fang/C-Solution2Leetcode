#include <iostream>
using namespace std;
struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k);
    ListNode* rotate(ListNode* head);
};

int main(int argc,char ** argv){
	cout<<"hello"<<endl;
	return 0;
}

ListNode* Solution::rotateRight(ListNode* head, int k){
	if(!head){
		return NULL;
	}
	int l=1;
	ListNode *current_node=head;
	while(current_node->next){
		current_node=current_node->next;
		l++;
	}
	int number=k%l;
	ListNode* input=head;
	for(int i=0;i<number;i++){
		input=rotate(input);
	}
	return input;
}

ListNode* Solution::rotate(ListNode* head){
	ListNode *current_node=head;
	ListNode *previous_node=head;
	ListNode *tail;
	while(current_node->next){
		previous_node=current_node;
		current_node=current_node->next;
	}
	tail=current_node;
	tail->next=head;
	previous_node->next=NULL;
	return tail;
}