#include <iostream>
using namespace std;

 struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };

class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        TreeNode* res = NULL;
        TreeNode* father = NULL;
        TreeNode* tmp = NULL;
        TreeNode* tmpper = NULL;
        DFS(root, NULL, key, father, res);
        if(res && father){
          if(res->left == NULL && res->right == NULL){
            if(father->left == res){
              father->left = NULL;
            }else{
              father->right = NULL;
            }
          }else if(res->left != NULL && res->right == NULL){
            if(father->left == res){
              father->left = res->left;
            }else{
              father->right = res->left;
            }
          }else if(res->left == NULL && res->right != NULL){
            if(father->left == res){
              father->left = res->right;
            }else{
              father->right = res->right;
            }
          }else{
            tmpper = res;
            tmp = res->left;
            if(tmp->right == NULL){
              tmp->right = res->right;

            }else{
              while(tmp->right){
                tmpper = tmp;
                tmp = tmp->right;
              }
              tmpper->right = tmp->left;
              tmp->left = res->left;
              tmp->right = res->right;
            }
            if(father->left == res){
              father->left = tmp;
            }else{
              father->right = tmp;
            }
            return root;
          }
        }else if(res && father == NULL){
          if(res->left == NULL && res->right == NULL){
            return NULL;
          }else if(res->left != NULL && res->right == NULL){
            return res->left;
          }else if(res->left == NULL && res->right != NULL){
            return res->right;
          }else{
            tmpper = res;
            tmp = res->left;
            if(tmp->right == NULL){
              tmp->right = res->right;
            }else{
              while(tmp->right){
                tmpper = tmp;
                tmp = tmp->right;
              }
              tmpper->right = tmp->left;
              tmp->left = res->left;
              tmp->right = res->right;
            }
            return tmp;
          }
        }

        return root;
    }

    void DFS(TreeNode* node, TreeNode* upper, int& key, TreeNode*& father, TreeNode*& res){
      if(node == NULL){
        return;
      }
      if(node->val == key){
        res = node;
        father = upper;
        return;
      }
      if(node->left && key<node->val){
        DFS(node->left, node, key, father, res);
      }
      if(node->right && key>node->val){
        DFS(node->right, node, key, father, res);
      }
      return;
    }

};

int main()
{

}