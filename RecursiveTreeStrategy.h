#ifndef __RECURSIVE_TREE_STRATEGY_H
#define __RECURSIVE_TREE_STRATEGY_H

#include "TreeStrategy.h"
#include <iostream>

class RecursiveTreeStrategy : public TreeStrategy
{
public:
    RecursiveTreeStrategy();
    ~RecursiveTreeStrategy();
    TreeNode* insert(TreeNode* node, int data);
    void print(TreeNode* node, int level);
    TreeNode* search(TreeNode* node, int data);
    TreeNode* erase(TreeNode* node, int data);

private:

    TreeNode* minValueNode(TreeNode* node);
};

#endif // __RECURSIVE_TREE_STRATEGY_H
