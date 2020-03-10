//
// Created by leslie-fang on 2017/6/11.
//
#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void DFS(TreeNode* t1, TreeNode* t2){
    if(t1 && t2)
    {
        t1->val = t1->val + t2->val;
        if(t1->left && t2->left)
        {
            DFS(t1->left, t2->left);
        }else if(t2->left)
        {
            t1->left = t2->left;
        }
        if(t1->right && t2->right)
        {
            DFS(t1->right, t2->right);
        }else if(t2->right)
        {
            t1->right = t2->right;
        }
        
    }
    return;
}

TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
    TreeNode * root= NULL;
    if(t1 && t2)
    {
        root = t1;
        DFS(t1, t2);
    }else if(t1)
    {
        root = t1;
    }else
    {
        root = t2;
    }
    return root;
}

int main(){
    cout<<"hello"<<endl;

    return 0;
}