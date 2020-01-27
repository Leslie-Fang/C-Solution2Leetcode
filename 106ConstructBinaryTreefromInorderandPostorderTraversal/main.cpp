#include <iostream>
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
	void dfs(TreeNode * root, vector<int>& inorder, vector<int>& postorder,const int & in_start, const int & in_end, const int & po_start, const int& po_end){
    	if(in_end <= in_start)
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
    			TreeNode * left_t = new TreeNode(postorder[po_start+left_tree_number-1]);
    			root->left = left_t;
    			dfs(left_t,inorder,postorder,in_start,in_left_index-1,po_start,po_start+left_tree_number-1);
    		}
    		if(right_tree_number>=1)
    		{
    			TreeNode * right_t = new TreeNode(postorder[po_end-1]);
    			root->right = right_t;
    			dfs(right_t,inorder,postorder,in_left_index+1,in_end,po_start+left_tree_number,po_start+left_tree_number+right_tree_number-1);
    		}
    	}
    	return;
	}
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    	if(postorder.size() > 0)
    	{
    		TreeNode * root = new TreeNode(postorder[postorder.size()-1]);
    		dfs(root, inorder, postorder, 0, inorder.size()-1, 0, postorder.size()-1);
    		return root;
    	}
    	return NULL;
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
	mySolution->buildTree(in, pn);
	delete mySolution;
	return 0;
}

