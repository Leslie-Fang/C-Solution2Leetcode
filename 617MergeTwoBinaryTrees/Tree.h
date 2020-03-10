//
// Created by leslie-fang on 2017/6/11.
//

#ifndef C_SOLUTION2LEETCODE_TREE_H
#define C_SOLUTION2LEETCODE_TREE_H

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

#endif //C_SOLUTION2LEETCODE_TREE_H
