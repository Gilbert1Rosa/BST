#ifndef __TREE_STRATEGY_H
#define __TREE_STRATEGY_H

#include "TreeNode.h"

class TreeStrategy
{
protected:
    TreeStrategy() {};
public:
    virtual TreeNode* insert(TreeNode* root, int data) = 0;
    virtual void print(TreeNode* root, int level) = 0;
    virtual TreeNode* search(TreeNode* root, int data) = 0;
    virtual TreeNode* erase(TreeNode* node, int data) = 0;
};

#endif // __TREE_STRATEGY_H
