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
    bool isValidBST(TreeNode* root) {
    	if(!root)
    	{
    		return true;
    	}
    	vector<int> rootlist_left;
    	vector<int> rootlist_right;
    	//rootlist.push_back(root->val);
    	return subisValidBST(root,rootlist_left,rootlist_right);  
    }
    bool subisValidBST(TreeNode* root,vector<int> rootlist_left,vector<int> rootlist_right)
   	{
   		bool isleft = true;
		bool isright = true;
   		if(!root)
    	{
    		return true;
    	}

    	for(vector<int>::iterator it=rootlist_left.begin();it != rootlist_left.end();it++)
    	{
    		if(root->val >= *it)
	    	{
	    		return false;
	    	}
    	}
    	for(vector<int>::iterator it=rootlist_right.begin();it != rootlist_right.end();it++)
    	{
    		if(root->val <= *it)
	    	{
	    		return false;
	    	}
    	}
    	if(root->left)
    	{
    		rootlist_left.push_back(root->val);
    		isleft = subisValidBST(root->left,rootlist_left,rootlist_right);
    	}
    	if(root->right)
    	{
    		if(root->left)
    		{
    			rootlist_left.pop_back();
    		}
			rootlist_right.push_back(root->val);
			isright = subisValidBST(root->right,rootlist_left,rootlist_right);
    	}
    	return isleft && isright; 
   	}

};

int main()
{
	Solution * mySolution = new Solution();
	TreeNode* root;
	cout<<mySolution->isValidBST(root)<<endl;

}