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
        bool last_level = false;
        int next_level_num_node = 0;
        bool find_first_next_level_node = false;
    	while(!last_level){
    		cur = level_start_node;
            next_level_num_node = 0;
            find_first_next_level_node = false;
            last_level = true;
            for(int i=0;i<num_level_node;i++){
                if(!find_first_next_level_node){
                    if(cur->left){
                        last_level = false;
                        level_start_node = cur->left;
                        find_first_next_level_node =true;
                        next_level_num_node += 1;
                        if(cur->right){
                            next_level_num_node += 1;
                            cur->left->next = cur->right;
                            tmp = cur->right;
                        }else{
                            tmp = cur->left;
                        }
                    }else if(cur->right){
                        last_level = false;
                        next_level_num_node += 1;
                        level_start_node = cur->right;
                        find_first_next_level_node = true;
                        tmp = cur->right;
                    }
                }else{
                    if(cur->left){
                        last_level = false;
                        tmp->next = cur->left;
                        next_level_num_node += 1;
                        if(cur->right){
                            next_level_num_node += 1;
                            cur->left->next = cur->right;
                            tmp = cur->right;
                        }else{
                            tmp = cur->left;
                        }
                    }else if(cur->right){
                        last_level = false;
                        next_level_num_node += 1;
                        tmp->next = cur->right;
                        tmp = cur->right;
                    }
                }
                cur = cur->next;
            }
            num_level_node = next_level_num_node;
    	}
    	return root;
    }
};

int main(int argc, char ** argv){

	return 0;
}