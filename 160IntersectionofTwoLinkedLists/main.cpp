#include <iostream>
using namespace std;
 struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB);
};
int main(){
	cout<<"Hello World"<<endl;

	ListNode * headA = new ListNode(1);
	ListNode * headB = new ListNode(2);
	Solution * mySolution = new Solution();
	cout<<mySolution->getIntersectionNode(headA,headB)->val<<endl;
	delete headA;
	delete headB;
	return 1;
}

ListNode * Solution::getIntersectionNode(ListNode *headA, ListNode *headB){
	ListNode * cA, * cB;
	int headALength = 0;
	int headBLength = 0;
	cA = headA;
	cB = headB;
	while(cA != NULL){
		headALength++;
		cA = cA->next;
	}
	while(cB != NULL){
		headBLength++;
		cB = cB->next;
	}
	int diff=0;
	cA = headA;
	cB = headB;
	if(headALength>headBLength){
		diff = headALength-headBLength;
		for(int i=0;i<diff;i++){
			cA = cA->next;
		}
		while(cA != NULL){
			if(cA == cB){
				return cA;
			}
			cA = cA->next;
			cB = cB->next;
		}
		return NULL;

	}else{
		diff = headBLength-headALength;
		for(int i=0;i<diff;i++){
			cB = cB->next;
		}
		while(cA != NULL){
			if(cA == cB){
				return cA;
			}
			cA = cA->next;
			cB = cB->next;
		}
		return NULL;
	}

	return NULL;
}