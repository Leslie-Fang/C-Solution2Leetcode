#include <iostream>
#include <limits>  
using namespace std;
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
class Solution {
public:
    int getMinimumDifference(TreeNode* root) {
    	int min = std::numeric_limits<int>::max();
    	int right_left = 0;
    	int left_right = 0;
    	int temp = 0;
    	if(root->left)
    	{
    		temp = abs(root->val-find_left_right(root->left));
    		min = temp<min?temp:min;
    		left_right = getMinimumDifference(root->left);
    		min = left_right<min?left_right:min;
    	}
    	if(root->right)
    	{
			temp = abs(root->val-find_right_left(root->right));
			min = temp<min?temp:min;
    		right_left = getMinimumDifference(root->right);
    		min = right_left<min?right_left:min;
    	}
        return min;
    }
    int find_right_left(TreeNode* root)
    {
    	TreeNode* res = root;
    	while(res->left)
    	{
    		res = res -> left;
    	}
    	return res->val;
    }
    int find_left_right(TreeNode* root)
    {
    	TreeNode* res = root;
    	while(res->right)
    	{
    		res = res -> right;
    	}
    	return res->val;
    }
};

int main(int argc, char ** argv)
{
	Solution * mySolution = new Solution();
	delete mySolution;
	return 0;

}