#ifndef __BSTREE_H
#define __BSTREE_H

#include "RecursiveTreeStrategy.h"

class BSTree
{
    TreeNode* root;
    TreeStrategy* strategy;
public:
    BSTree();
    ~BSTree();
    void print();
    void insert(int data);
    bool search(int data);
    void erase(int data);
};

#endif // __BSTREE_H
