#include <iostream>
using namespace std;
struct ListNode{
	ListNode * next;
	int val;
	ListNode(int x) : val(x), next(NULL){}
};
void reverse(ListNode * root);

int main(){
	return 0;
}

ListNode * reverse(ListNode * root){
	if(root == NULL || root->next == NULL){
		return root;
	}
	ListNode * pre = NULL,* cur = root,* nextNode = root->next;
	while(true){
		cur->next = pre;
		pre = cur;
		cur = nextNode;
		if(nextNode->next != NULL){
			nextNode = cur->next;
		}else{
			break;
		}
	}
	cur->next = pre;
	return cur;
}