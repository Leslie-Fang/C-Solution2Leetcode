#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
class BSTIterator {
public:
	vector<TreeNode*> res;
	int ite;
    BSTIterator(TreeNode* root) {
    	if(root == NULL)
    	{
    		res = {};

    	}else{
    		 DFS(root);
    	}
        ite = 0;
    }
    
    void DFS(TreeNode* root)
    {
    	if(root->left)
    	{
    		DFS(root->left);
    	}
    	res.push_back(root);
    	if(root->right)
    	{
    		DFS(root->right);
    	}
    	return;
    }
    /** @return the next smallest number */
    int next() {
    	int temp = res[ite]->val;
    	ite += 1;
    	return temp;
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        if(ite < res.size())
        {
        	return true;
        }else
        {
        	return false;
        }
    }
};

int main()
{
	return 1;
}