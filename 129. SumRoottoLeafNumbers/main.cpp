#include <iostream>
#include <string>
#include <vector>
using namespace std;

 struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
public:
    int sumNumbers(TreeNode* root);
};

void DFS(TreeNode* root,int * res,int cSum);

int main(int argc,char** argv){
	TreeNode root(10);
	Solution * mySolution = new Solution();
	cout<<mySolution->sumNumbers(&root)<<endl;

	return 0;
}

int Solution::sumNumbers(TreeNode* root){
	int res=0,cSum=0;
	if(root == NULL){
		return 0;
	}
	DFS(root,&res,cSum);

	return res;
}

void DFS(TreeNode* root,int * res,int cSum){
	if(root == NULL){
		return;
	}
	cSum = cSum*10+root->val;
	if(root->left ==NULL && root->right == NULL){
		*res += cSum;
		return;
	}
	if(root->left != NULL){
		DFS(root->left,res,cSum);
	}
	if(root-> right != NULL){
		DFS(root->right,res,cSum);
	}
	return;
}