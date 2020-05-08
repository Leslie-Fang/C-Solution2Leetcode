#include <iostream>
#include <vector>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
	void DFS(TreeNode* node, vector<int> & temp, int & res, int & sum) {
		if(node == NULL)
		{
			return;
		}
		if(node->val == sum)
		{
			res += 1;
		}
		vector<int> temp2;
		for(auto num : temp)
		{
			if(node->val + num == sum)
			{
				res += 1;
			}
			temp2.push_back(node->val + num);
		}
	    temp2.push_back(node->val);
	    if(node->left)
	    {
            DFS(node->left, temp2, res, sum);
	    }
	    if(node->right)
	    {
            DFS(node->right, temp2, res, sum);
	    }
		return;
	}
    int pathSum(TreeNode* root, int sum) {
        int res = 0;
        vector<int> temp;
        DFS(root, temp, res, sum);
        return res;
    }
};

int main(int argc, char ** argv) {
	return 1;
}