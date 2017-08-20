//
// Created by leslie-fang on 2017/8/20.
//
#include <iostream>

using namespace std;

bool pFind= false, qFind= false;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if(!root || root == p || root == q){
        return root;
    }
    TreeNode* left = lowestCommonAncestor(root->left, p, q);
    TreeNode* right = lowestCommonAncestor(root->right, p, q);
    //if left and right, in the same subTree, return the root of the subTree
    if(left && right) return root;
    return left?left:right;
}

int main(){
    cout<<"hello world!"<<endl;
    return 0;
}
