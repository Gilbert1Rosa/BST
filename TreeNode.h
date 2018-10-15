#ifndef __TREENODE_H
#define __TREENODE_H

enum TreeFlag {
    RED,
    BLACK
};

struct TreeNode
{
    int data;
    TreeFlag color;
    TreeNode* parent;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int data)
    {
        this->data = data;
        left = 0;
        right = 0;
        color = RED;
    }
};

#endif // __TREENODE_H
