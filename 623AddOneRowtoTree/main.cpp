//
// Created by leslie-fang on 2017/7/17.
//
#include<iostream>
using namespace std;

struct TreeNode {
         int val;
         TreeNode *left;
         TreeNode *right;
         TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void justaddOneRow(TreeNode* root, int v, int d,int cd){
    if(!root){
        return;
    }
    if(cd != d-1){
        justaddOneRow(root->left,v,d,cd+1);
        justaddOneRow(root->right,v,d,cd+1);
    }else{
        TreeNode *a = new TreeNode(v);
        a->left = root->left;
        root->left = a;

        TreeNode *b = new TreeNode(v);
        b->right = root->right;
        root->right = b;
        return;
    }
}

TreeNode* addOneRow(TreeNode* root, int v, int d) {
    if(!root){
        return ;
    }
    if(d ==1){
        TreeNode *a = new TreeNode(v);
        a->left = root;
        return a;
    }
    justaddOneRow(root,v,d,1);

    return root;
}

int main(){
    cout<<"hello world!"<<endl;
    return 0;
}

