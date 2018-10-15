#include "RedBlackStrategy.h"

TreeNode* RedBlackStrategy::insert(TreeNode* root, int data)
{
    return RecursiveTreeStrategy::insert(root, data);
}

void RedBlackStrategy::print(TreeNode* root, int level)
{
    return RecursiveTreeStrategy::print(root, level);
}

TreeNode* RedBlackStrategy::search(TreeNode* root, int data)
{
    return RecursiveTreeStrategy::search(root, data);
}

TreeNode* RedBlackStrategy::erase(TreeNode* node, int data)
{
    return RecursiveTreeStrategy::erase(root, data);
}

void RedBlackStrategy::fixViolation(TreeNode* root, TreeNode* pt)
{
    TreeNode* parent_pt = NULL;
    TreeNode* grand_parent_pt = NULL;

    while(pt != root) &&
          pt->color == BLACK &&
          pt->parent->color == RED) {

        parent_pt = pt->parent;
        grand_parent_pt = pt->parent->parent;

        if (parent_pt == grand_parent_pt->left) {
            TreeNode* uncle_pt = grand_parent_pt->right;

            if (uncle_pt != NULL && uncle_pt->color == RED) {
                grand_parent_pt->color = RED;
                parent_pt->color = BLACK;
                uncle_pt->color = BLACK;
                pt = grand_parent_pt;
            }
            else {
                if (pt == parent_pt->right) {
                    rotateLeft(root, parent_pt);
                    pt = parent_pt;
                    parent_pt = pt->parent;
                }

                rotateLeft(root, grand_parent_pt);
                swap(parent_pt->color, grand_parent_pt->color);
                pt = parent_pt;
            }
        }
    }
    root->color = BLACK;
}

void RedBlackStrategy::rotateLeft(TreeNode* root, TreeNode* pt)
{

}

void RedBlackStrategy::rotateRight(TreeNode* root, TreeNode* pt)
{

}
