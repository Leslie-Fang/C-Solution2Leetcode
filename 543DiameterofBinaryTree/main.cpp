#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <string.h>
using namespace std;
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     int left_depth;
     int right_depth;
     TreeNode(int x) : val(x), left(NULL), right(NULL), left_depth(0), right_depth(0) {}
  };
class Solution {
public:
	int DFS(TreeNode * node, int & res)
	{
		if(!node)
		{
			return 0;
		}
		int left_depth = DFS(node->left, res);
		int right_depth = DFS(node->right, res);
		if(left_depth+right_depth > res)
		{
			res = left_depth+right_depth;
		}
		return left_depth>right_depth?left_depth+1:right_depth+1;
	}
    int diameterOfBinaryTree(TreeNode* root) {
    	int res = 0;
    	DFS(root, res);
    	return res;
    }
};

int main(int argc, char ** argv)
{
	return 1;
}