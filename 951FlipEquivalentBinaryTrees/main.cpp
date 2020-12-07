#include <iostream>
using namespace std;

// class Solution {
// public:
//     bool flipEquiv(TreeNode* root1, TreeNode* root2) {
//     	if(root1 == NULL && root2 == NULL){
//     		return true;
//     	}
//     	if(root1 == NULL || root2 == NULL){
//     		return false;
//     	}
//     	if(root1->val != root2->val){
//     		return false;
//     	}
//     	bool flipe = true;
//     	if((root1->left != NULL && root2->right != NULL) || (root1->left == NULL && root2->right == NULL)){
//     		flipe = flipe && flipEquiv(root1->left, root2->right);
//     	}else{
//     		return false;
//     	}
//     	if((root1->right != NULL && root2->left != NULL) || (root1->right == NULL && root2->left == NULL)){
//     		flipe = flipe && flipEquiv(root1->right, root2->left);
//     	}else{
//     		return false;
//     	}
//     	return flipe;
//     }
// };

class Solution {
public:
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        if(root1 == NULL && root2 == NULL){
    		return true;
    	}
    	if(root1 == NULL || root2 == NULL){
    		return false;
    	}
    	if(root1->val != root2->val){
    		return false;
    	}
    	bool flipequal = true;
    	bool fliptrue = true;
    	//use equal
		if((root1->left == NULL && root2->left == NULL) || (root1->left != NULL && root2->left != NULL)){
			flipequal = flipEquiv(root1->left, root2->left);
		}else{
			flipequal = false;
		}
		if(((root1->right == NULL && root2->right == NULL) || (root1->right != NULL && root2->right != NULL)) && flipequal){
			flipequal = flipEquiv(root1->right, root2->right);
		}else{
			flipequal = false;
		}
		//use flip
    	if((root1->left != NULL && root2->right != NULL) || (root1->left == NULL && root2->right == NULL)){
    		fliptrue = fliptrue && flipEquiv(root1->left, root2->right);
    	}else{
    		fliptrue = false;
    	}
    	if(((root1->right != NULL && root2->left != NULL) || (root1->right == NULL && root2->left == NULL)) && fliptrue){
    		fliptrue = fliptrue && flipEquiv(root1->right, root2->left);
    	}else{
    		fliptrue = false;
    	}
		return flipequal || fliptrue;

    }
};

int main(int argc, char ** argv){

	return 0;
}