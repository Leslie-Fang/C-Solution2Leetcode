#include <iostream>
#include "listnode.hpp"
using namespace std;

void reverse(ListNode * root){
	ListNode * current = root;
	ListNode * previous,next = NULL;
	// ListNode * temp = NULL;
	// if(current->next != NULL){
	// 	ListNode * next = current->next;
	// }else{
	// 	return current;
	// }
	while(current->next != NULL){
		next = current->next;
		current->next = previous;

		previous = current;
		current = next;
	}
	current->next = previous;
	return current;
}

void insert(ListNode * root,ListNode * Node, int pos){
	ListNode * current=root;
	for(int i=0;i<pos;i++){
		current = current->next;
	}
	ListNode * temp = next;
	current->next = Node;
	Node->next = temp;

}

