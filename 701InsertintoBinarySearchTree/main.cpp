#include <iostream>
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
	void DFS(TreeNode* father, TreeNode* node, const int val, bool left){
		if(node == NULL){
			TreeNode * insert = new TreeNode(val);
			if(father == NULL){
				node = insert;
				return;
			}else{
				if(left){
					father->left = insert;
				}else{
					father->right = insert;
				}
			}
		}else{
			if(node->val >= val){
				DFS(node, node->left, val, true);
			}else{
				DFS(node, node->right, val, false);
			}

		}

	}
    TreeNode* insertIntoBST(TreeNode* root, int val) {
    	if(root == NULL){
    		return new TreeNode(val);
    	}
        DFS(NULL, root, val, false);
        return root;
    }
};

int main(int argc, char ** argv){

}