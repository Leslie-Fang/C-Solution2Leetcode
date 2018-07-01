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
    TreeNode* cNode;
    void DFS(TreeNode* root);
};
int main(){
	cout<<"Hello World!"<<endl;
	return 1;
}
void Solution::flatten(TreeNode* root){
	if(root == NULL){
		return;
	}
	this->cNode = root;
	this->DFS(root);
	return;
}

void Solution::DFS(TreeNode* root){
	TreeNode * left = root->left;
	TreeNode * right = root->right;
	if(left != NULL){
		this->cNode->right = left;
		this->cNode = this->cNode->right;
		DFS(left);
	}
	if(right != NULL){
		this->cNode->right = right;
		this->cNode = this->cNode->right;
		DFS(right);
	}
	return;

}
