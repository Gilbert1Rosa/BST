#include "BSTree.h"

BSTree::BSTree()
{
    root = NULL;
    strategy = new RecursiveTreeStrategy();
}

BSTree::~BSTree()
{

}

void BSTree::print()
{
    strategy->print(root, 1);
}

void BSTree::insert(int data)
{
    root = strategy->insert(root, data);
}

bool BSTree::search(int data)
{
    TreeNode* node = strategy->search(root, data);
    return node != NULL && data == node->data;
}

void BSTree::erase(int data)
{
    strategy->erase(root, data);
}
