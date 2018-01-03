//
// Created by leslie-fang on 2017/8/13.
//
#include <iostream>
#include <vector>

using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void getValue(TreeNode* node, vector<int> &res){
    if(node){
        res.push_back(node->val);
    }
    if(node->left){
        getValue(node->left,res);
    }
    if(node->right){
        getValue(node->right,res);
    }
    return;
}

vector<int> preorderTraversal(TreeNode* root) {
    vector<int> res;
    if(root){
        getValue(root,res);
    }
    return res;
}

int main(){
    cout<<"Hello world"<<endl;
    TreeNode *root = new TreeNode(10);
    cout<<root->val<<endl;
    return 0;
}

