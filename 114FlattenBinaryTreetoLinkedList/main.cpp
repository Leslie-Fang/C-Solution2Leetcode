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
    void flatten(TreeNode* root);
};
int main(){
	cout<<"Hello World!"<<endl;
}
void Solution::flatten(TreeNode* root){

	return;
}

void DFS(TreeNode* root){
	if(root == NULL){
		return;
	}
	if(root->left != NULL){
		if(root->right != NULL){
			TreeNode* right = root->right;
		}
		root->right = root->left;
		DFS(root->left);
		DFS(right);
	}
	if(root->right != NULL){
		DFS(root->right);
	}
	return;

}