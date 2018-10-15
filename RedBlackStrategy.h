#ifndef __RED_BLACK_STRATEGY_H
#define __RED_BLACK_STRATEGY_H

#include "RecursiveTreeStrategy.h"

class RedBlackStrategy : public RecursiveTreeStrategy
{
public:
    TreeNode* insert(TreeNode* root, int data);
    void print(TreeNode* root, int level);
    TreeNode* search(TreeNode* root, int data);
    TreeNode* erase(TreeNode* node, int data);
private:
    void fixViolation(TreeNode* root, TreeNode* pt);
    void rotateLeft(TreeNode* root, TreeNode* pt);
    void rotateRight(TreeNode* root, TreeNode* pt);
};

#endif // __RED_BLACK_STRATEGY_H
