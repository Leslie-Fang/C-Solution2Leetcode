#include <iostream>
#include "tree.hpp"
using namespace std;

void baniary_search(TreeNode * root,int value){
	if(root->val == value){
		return;
	}else if(root->val < value){
		baniary_search(root->right,value);
	}else{
		baniary_search(root->left,value);
	}
}

void baniary_insert(TreeNode * root,TreeNode * Node){
	if(root->val == value){
		return;
	}else if(root->val < value){
		if(root->right != NULL){
			baniary_insert(root->right,value);
		}else{
			root->right = Node;
			return;
		}
	}else{
		if(root->left != NULL){
			baniary_insert(root->left,value);
		}else{
			root->left = Node;
			return;
		}
	}
}

void baniary_delete(TreeNode * root,TreeNode * Node){
	if(root->val == value){

		if(root->right == NULL){

		}

		return;
	}
}