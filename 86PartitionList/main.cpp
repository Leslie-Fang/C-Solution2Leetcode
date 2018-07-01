
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <queue>
using namespace std;
struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
    ListNode* partition(ListNode* head, int x);
};

int main(int argc,char** argv){
	ListNode root(10);
	Solution * mySolution = new Solution();
	//cout<<mySolution->findMode(&root)<<endl;
	mySolution->partition(&root,10);

	return 0;
}

ListNode* Solution::partition(ListNode* head, int x){
	ListNode* res;
	ListNode* left=NULL;
	ListNode* leftTemp=NULL;
	ListNode* right=NULL;
	ListNode* rightTemp=NULL;
	if(head == NULL){
		return head;
	}
	while(head != NULL){
		if(head->val < x){
			if(left == NULL){
				left = new ListNode(head->val);
				leftTemp = left;
			}else{
				leftTemp->next= new ListNode(head->val);
				leftTemp = leftTemp->next;
			}
		}else{
			if(right == NULL){
				right = new ListNode(head->val);
				rightTemp = right;
			}else{
				rightTemp->next = new ListNode(head->val);
				rightTemp = rightTemp->next;
			}
		}
		head = head->next;
	}
	if(left == NULL){
		return right;
	}
	leftTemp->next=right;
	return left;
}