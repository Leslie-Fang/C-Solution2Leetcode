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
    TreeNode* sortedArrayToBST(vector<int>& nums);
};
TreeNode* help(vector<int>& nums,int start, int end);
int main(){
	cout<<"Hello!"<<endl;
}

TreeNode* Solution::sortedArrayToBST(vector<int>& nums){
	if(nums.size() == 0){
		return NULL;
	}
	TreeNode* root = help(nums,0,nums.size()-1);
	return root;
}

TreeNode* help(vector<int>& nums,int start, int end){
	if(start > end){
		return NULL;
	}
	int rootIndex = (start+end)/2;
	TreeNode* root = new TreeNode(nums[rootIndex]);
	root->left = help(nums,start,rootIndex-1);
	root->right = help(nums,rootIndex+1,end);
	return root;
}

