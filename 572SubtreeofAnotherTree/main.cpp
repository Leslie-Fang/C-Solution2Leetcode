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
	bool DPS_same_tree(TreeNode* s, TreeNode* t)
	{
		if(s == NULL || t == NULL || s->val != t->val)
		{
			return false;
		}
		if(s->left != NULL)
		{
			if(t->left == NULL)
			{
				return false;
			}else
			{
				if(!DPS_same_tree(s->left, t->left))
				{
					return false;
				}
			}
		}else{
			if(t->left != NULL)
			{
				return false;
			}
		}
		if(s->right != NULL)
		{
			if(t->right == NULL)
			{
				return false;
			}else
			{
				if(!DPS_same_tree(s->right, t->right))
				{
					return false;
				}
			}
		}else{
			if(t->right != NULL)
			{
				return false;
			}
		}
		return true;
	}
	bool is_same_tree(TreeNode* s, TreeNode* t)
	{
		return DPS_same_tree(s, t);
	}
	bool DPS(TreeNode* s, TreeNode* t)
	{
		if(s->val == t->val)
		{
			if(is_same_tree(s,t))
			{
				return true;
			}
		}
		if(s->left)
		{
			if(DPS(s->left, t))
			{
				return true;
			}
		}
		if(s->right)
		{
			if(DPS(s->right, t))
			{
				return true;
			}
		}
		return false;
	}
    bool isSubtree(TreeNode* s, TreeNode* t) {
        return DPS(s, t);
    }
};

int main(int argc, char ** argv){
	return 0;
}