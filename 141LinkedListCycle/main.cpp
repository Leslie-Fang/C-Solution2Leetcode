#include <iostream>
using namespace std;

 struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
    bool hasCycle(ListNode *head);
};

int main(int argc,char ** argv){
	cout<<"Hello"<<endl;
	Solution * mySolution = new Solution();
	ListNode * myListNode = new ListNode(10);
	mySolution->hasCycle(myListNode);

}

bool Solution::hasCycle(ListNode *head){
	bool res = true;
	if(head == NULL || head->next == NULL || head->next->next == NULL){
		return false;
	}
	ListNode * myListNode1 = head->next;
	ListNode * myListNode2 = head->next->next;
	while(1){
		if(myListNode1 == myListNode2){
			return true;
		}
		myListNode1 = myListNode1->next;
		if(myListNode2->next == NULL || myListNode2->next->next == NULL){
			return false;
		}
		myListNode2 = myListNode2->next->next;

	}
	return res;
}