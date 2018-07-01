#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <queue>
using namespace std;

 struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
public:
    vector<int> rightSideView(TreeNode* root);
};

void DFS(TreeNode* root, map<int, int> & mapStudent);

int main(int argc,char** argv){
	TreeNode root(10);
	Solution * mySolution = new Solution();
	//cout<<mySolution->findMode(&root)<<endl;
	mySolution->rightSideView(&root);

	return 0;
}

vector<int> Solution::rightSideView(TreeNode* root){
	vector<int> res;
	queue<TreeNode*> cRes;
	if(root == NULL){
		return res;
	}
	cRes.push(root);
	int length=0;
	TreeNode* current;
	while(!cRes.empty()){
		length = cRes.size();
		res.push_back(cRes.back()->val);
		for(int i=0;i<length;i++){
			current = cRes.front();
			if(current->left != NULL){
				cRes.push(current->left);
			}
			if(current->right != NULL){
				cRes.push(current->right);
			}
			cRes.pop();
		}
	}
	return res;
}
