#include <iostream>
#include <vector>
using namespace std;

 struct TreeNode
 {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
 
class Solution {
public:
	void deepFirstSearch(TreeNode* root,bool count)
	{
		if(root->left == NULL && root->right == NULL && count)
		{
			leaves.push_back(root->val);
			return;
		}
		if(root->left != NULL)
		{
			deepFirstSearch(root->left,true);
		}
		if(root->right != NULL)
		{
			deepFirstSearch(root->right,false);
		}
		return;

	}
    int sumOfLeftLeaves(TreeNode* root)
    {
    	if(root == NULL)
		{
			return 0;
		}
    	int sum =0;
        deepFirstSearch(root,false);
        for(vector<int>::iterator it=leaves.begin();it !=leaves.end();it++)
        {
			sum = sum + *it;
        }
        return sum;
    }

private:
	vector<int> leaves;
};

int main(int argc,char ** argv)
{
	cout<<"Hello World!"<<endl;
	Solution * mySolution = new Solution();
	TreeNode* root;
	mySolution->sumOfLeftLeaves(root);
	return 0;

}