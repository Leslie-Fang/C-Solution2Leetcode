//
// Created by leslie-fang on 2017/6/11.
//
#include <iostream>
#include "Tree.h"

using namespace std;
TreeNode* searchTree(TreeNode* t1){
    if(t1 == NULL){
        return t1;
    }
    if(t1->left != NULL){
        searchTree(t1->left);
    }
    if(t1->right !=NULL ){
        searchTree(t1->right);
    }
    return t1;
}

TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
    if (t1 == NULL){
        return t2;
    }
    else if( t2 == NULL ){
        return t1;
    }
    if(t1->left != NULL || t2->left != NULL){
        mergeTrees(t1->left,t2->left);
    }
    if(t1->right != NULL || t2->right != NULL){
        mergeTrees(t1->right,t2->right);
    }
 //   t1->val=t1->val+t2->val;
  //  return t1;
    TreeNode * xinjian=new TreeNode();
    xinjian->val=t1->val+t2->val;
    xinjian->left=NULL;
    xinjian->right=NULL;
    return xinjian;
}

int main(){
    cout<<"hello"<<endl;

    return 0;
}