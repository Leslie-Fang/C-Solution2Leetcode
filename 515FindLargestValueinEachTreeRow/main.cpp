#include <iostream>
#include <queue>
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
    vector<int> largestValues(TreeNode* root);
};

int main(int argc, char ** argv){
	cout<<"hello!"<<endl;
	TreeNode root(10);
	Solution * mySolution = new Solution();
	mySolution->largestValues(&root);
}

vector<int> Solution::largestValues(TreeNode* root){
	vector<int> res;
	int tempLength=0;
	int cLarger=0;
	if(root == NULL){
		return res;
	}
	queue<TreeNode*> myQueue;
	myQueue.push(root);
	tempLength = myQueue.size();
	cLarger = root->val;
	while(tempLength != 0){
		cLarger = myQueue.front()->val;
		for(int i=0;i<tempLength;i++){
			if(myQueue.front()->val > cLarger){
				cLarger = myQueue.front()->val;
			}
			if(myQueue.front()->left != NULL){
				myQueue.push(myQueue.front()->left);
			}
			if(myQueue.front()->right != NULL){
				myQueue.push(myQueue.front()->right);
			}
			myQueue.pop();
		}
		tempLength = myQueue.size();
		res.push_back(cLarger);
	}
	return res;
}