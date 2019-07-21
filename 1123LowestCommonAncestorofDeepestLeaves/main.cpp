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
	vector<TreeNode *> FindDeepestLeaves(TreeNode* root){
		vector<TreeNode *> res;
		if(!root)
		{
			return res;
		}
		res.push_back(root);
		int count = 0;
		while(1)
		{
			count=res.size();
			int hint = 0;
			for(int i=0;i<count;i++)
			{
				if(res[i]->left){
					res.push_back(res[i]->left);
					hint +=1;
				}
				if(res[i]->right)
				{
					res.push_back(res[i]->right);
					hint +=1;
				}
			}
			if(hint == 0)
			{
				break;
			}
			res.erase(res.begin(),res.begin()+count);
		}
		return res;
	}

	TreeNode* FindPartent(TreeNode* cRoot, TreeNode * node){
		if(!cRoot)
		{
			return NULL;
		}
		if(cRoot->left == node || cRoot->right == node)
		{
			return cRoot;
		}
		TreeNode * res = FindPartent(cRoot->left,node);
		return res?res:FindPartent(cRoot->right,node);
	}

    TreeNode* lcaDeepestLeaves(TreeNode* root) {
		vector<TreeNode *> leaves = FindDeepestLeaves(root);
		if(leaves.size() == 0)
		{
			return NULL;
		}
		while(leaves.size() != 1)
		{
			int count = leaves.size();
			TreeNode * pNode =NULL;
			TreeNode * cNode =NULL;
			for(int i=0;i<count;i++)
			{
				cNode = FindPartent(root,leaves[i]);
				if(pNode != cNode)
				{
					leaves.push_back(cNode);
				}
				pNode = cNode;
			}
			leaves.erase(leaves.begin(),leaves.begin()+count);
		}
        return leaves[0];
    }
};

int main(int argc, char ** argv)
{
	Solution * mySolution = new Solution();
	TreeNode* root;
	mySolution->lcaDeepestLeaves(root);
	return 0;
}