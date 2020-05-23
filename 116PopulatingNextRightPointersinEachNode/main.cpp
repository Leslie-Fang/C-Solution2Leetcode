#include <iostream>
using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
public:
    Node* connect(Node* root) {
    	if(root == NULL){
    		return root;
    	}
    	Node* cur = root;
    	Node* tmp = root;
    	Node* level_start_node = root;
    	int num_level_node = 1;
    	while(true){
    		cur = level_start_node;
    		if(cur->left == NULL && cur->right == NULL){
    			break;
    		}
            for(int i=0;i<num_level_node;i++){
            	if(i == 0){
            		level_start_node = cur->left;
            	}else{
            		tmp->next = cur->left;
            	}
            	cur->left->next = cur->right;
	            tmp = cur->right;
            	cur = cur->next;
            }
            num_level_node *=2;
    	}
    	return root;
    }
};

int main(int argc, char ** argv){

	return 0;
}