#include <iostream>
#include <algorithm>
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    	if(preorder.size() > 0)
    	{
    		TreeNode * root = new TreeNode(preorder[0]);
    		dfs(root, preorder, inorder, 0, preorder.size()-1, 0, inorder.size()-1);
    		return root;
    	}
    	return NULL;
    }
    void dfs(TreeNode * root, vector<int>& preorder, vector<int>& inorder, int pn_start, int pn_end, int in_start, int in_end){
    	if(pn_end <= pn_start)
    	{
    		return;
    	}else
    	{
    		int in_left_index = in_start;
    		for(int i=in_start;i<=in_end;i++)
    		{
    			if(inorder[i] == root->val)
    			{
    				in_left_index = i;
    				break;
    			}
    		}
    		int left_tree_number = in_left_index-in_start;
    		int right_tree_number = in_end-in_left_index;
    		if(left_tree_number>=1)
    		{
    			TreeNode * left_t = new TreeNode(preorder[pn_start+1]);
    			root->left = left_t;
    			dfs(left_t,preorder,inorder,pn_start+1,pn_start+left_tree_number,in_start,in_left_index-1);
    		}
    		if(right_tree_number>=1)
    		{
    			TreeNode * right_t = new TreeNode(preorder[pn_start+left_tree_number+1]);
    			root->right = right_t;
    			dfs(right_t,preorder,inorder,pn_start+left_tree_number+1,pn_end,in_left_index+1,in_end);
    		}
    	}
    	return;
    }
};

int main(int argc, char ** argv)
{
	#define number 3
	int a[number] = {1,2,3};
	int b[number] = {3,2,1};
	vector<int> pn(a,a+number);
	vector<int> in(b,b+number);
	Solution * mySolution = new Solution();
	mySolution->buildTree(pn,in);
	delete mySolution;
	return 0;
}