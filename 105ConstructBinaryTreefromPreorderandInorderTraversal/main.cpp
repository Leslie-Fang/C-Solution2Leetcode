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
    		vector<int> left_tree;
    		for(int i=in_start;i<=in_end;i++)
    		{
    			if(inorder[i] == root->val)
    			{
    				in_left_index = i;
    				break;
    			}else{
    				left_tree.push_back(inorder[i]);
    			}
    		}
    		int pn_left_index = pn_start+1;
    		bool find_n = false;
    		for(int i=pn_start+1;i<=pn_end;i++)
    		{
    			vector<int>::iterator it = find(left_tree.begin(), left_tree.end(), preorder[i]);
    			if(it != left_tree.end())
    			{
    				left_tree.erase(it);
    			}else
    			{
    				pn_left_index = i;
    				find_n = true;
    				break;
    			}
    		}
    		if(!find_n)
    		{
    			pn_left_index = pn_end+1;
    		}
    		if(in_left_index != in_start)
    		{
    			TreeNode * left_t = new TreeNode(preorder[pn_start+1]);
    			root->left = left_t;
    			dfs(left_t,preorder,inorder,pn_start+1,pn_left_index-1,in_start,in_left_index-1);
    		}
    		if(in_left_index != in_end)
    		{
    			TreeNode * right_t = new TreeNode(preorder[pn_left_index]);
    			root->right = right_t;
    			dfs(right_t,preorder,inorder,pn_left_index,pn_end,in_left_index+1,in_end);
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