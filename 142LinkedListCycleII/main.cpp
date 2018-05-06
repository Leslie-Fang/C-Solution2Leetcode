#include <iostream>
using namespace std;

 struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
    ListNode *detectCycle(ListNode *head) ;
};

int main(int argc, char ** argv){
	cout<<"Hello!"<<endl;
	Solution * mySolution = new Solution();
	ListNode * myListNode = new ListNode(10);
	mySolution->detectCycle(myListNode);

}

ListNode * Solution::detectCycle(ListNode *head){
	ListNode * res;
	ListNode * meetNode;
	int steps=0;
	if(head == NULL || head->next == NULL || head->next->next == NULL){
		return NULL;
	}
	ListNode * myListNode1 = head->next;
	ListNode * myListNode2 = head->next->next;
	steps +=1;
	while(1){
		if(myListNode1 == myListNode2){
			meetNode = myListNode1;
			break;
		}
		myListNode1 = myListNode1->next;
		if(myListNode2->next == NULL || myListNode2->next->next == NULL){
			return NULL;
		}
		myListNode2 = myListNode2->next->next;
		steps +=1;
	}
	// int loopSteps=0;
	// while(1){
	// 	myListNode1 = myListNode1->next;
	// 	loopSteps +=1;
	// 	if(myListNode1 == meetNode){
	// 		break;
	// 	}
	// }
	myListNode1 = head;
	myListNode2 = meetNode;
	while(1){
		if(myListNode1 == myListNode2){
			return myListNode2;
		}
		myListNode1 = myListNode1->next;
		myListNode2 = myListNode2->next;
	}
	return res;
}