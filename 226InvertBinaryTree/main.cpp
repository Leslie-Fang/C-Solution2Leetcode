#include <iostream>

using namespace std;

 struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
public:
    TreeNode* invertTree(TreeNode* root);
};

int main(int argc, char ** argv){
	cout<<"Hello World"<<endl;
	return 0;


}

TreeNode* Solution::invertTree(TreeNode* root){
	if(root != NULL){
        if(root->left){
        	invertTree(root->left);
        }
        if(root->right){
        	invertTree(root->right);
        }
        if(root->left || root->right){
        	TreeNode* temp = root->left;
        	root->left = root->right;
        	root->right = temp;
        }
	}
	return root;
}
