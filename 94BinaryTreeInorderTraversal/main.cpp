#include<iostream>
#include<vector>
using namespace std;

 struct TreeNode {
      int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
public:
	void DPS(TreeNode* root, vector<int> & res)
	{
		if(root->left)
		{
			DPS(root->left,res);
		}
		res.push_back(root->val);
		if(root->right)
		{
			DPS(root->right,res);
		}
		return;
	}
    vector<int> inorderTraversal(TreeNode* root) {
    	vector<int> res;
    	if(root != NULL)
    	{
    		DPS(root, res);
    	}
    	return res;
    }
};
int main(int argc, char ** argv){
	return 0;
}