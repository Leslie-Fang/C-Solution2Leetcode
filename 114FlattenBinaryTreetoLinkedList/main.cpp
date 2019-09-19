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
	void DFS(TreeNode* root, TreeNode * &cNode){
		TreeNode * left = root->left;
		TreeNode * right = root->right;
		if(left != NULL){
			cNode->right = left;
			cNode->left = NULL;
			cNode = left;
			DFS(left, cNode);
			
		}
		if(right != NULL){
			cNode->right = right;
			cNode->left = NULL;
			cNode = right;
			DFS(right, cNode);
		}
		return;

	}
    void flatten(TreeNode* root){
		if(root == NULL){
			return;
		}
		TreeNode * cNode = root;
		DFS(root, cNode);
		return;
	}
};
int main(){
	cout<<"Hello World!"<<endl;
	return 1;
}

