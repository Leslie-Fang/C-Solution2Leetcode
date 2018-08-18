#include <iostream>
#include <vector>
#include <queue>
using namespace std;

 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
public:
    bool isSymmetric(TreeNode* root);
};

int main(int argc,char ** argv){
	cout<<"Hello"<<endl;
	// queue<int> a;
	// a.push(1);
	// cout<<a[0]<<endl;
	return 1;
}

bool Solution::isSymmetric(TreeNode* root){
       if(!root)
            return true;
        queue<TreeNode*> q1,q2;
        q1.push(root->left);
        q2.push(root->right);
        TreeNode*left,*right;
        while(!q1.empty() && !q2.empty())
        {
            left = q1.front();
            q1.pop();
            right = q2.front();
            q2.pop();
            if(left==NULL && right==NULL)
                continue;    
            else if(left == NULL || right == NULL)
                return false;
            else{
                if(left->val == right->val){
                    q1.push(left->left);
                    q1.push(left->right);
                    q2.push(right->right);
                    q2.push(right->left);
                    continue;
                }
                else
                    return false;
            }
            
        }
        return true;
}
