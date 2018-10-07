#include "RecursiveTreeStrategy.h"

RecursiveTreeStrategy::RecursiveTreeStrategy()
{

}

RecursiveTreeStrategy::~RecursiveTreeStrategy()
{

}

TreeNode* RecursiveTreeStrategy::insert(TreeNode* node, int data)
{
    if (node == NULL) {
        node = new TreeNode(data);
    } else {
        int tmpData = node->data;
        if (data < tmpData && node->left != NULL) {
            node->left = insert(node->left, data);
        } else if (data < tmpData && node->left == NULL) {
            node->left = new TreeNode(data);
        }

        if (data > tmpData && node->right != NULL) {
            node->right = insert(node->right, data);
        } else if (data > tmpData && node->right == NULL) {
            node->right = new TreeNode(data);
        }
    }
    return node;
}

void RecursiveTreeStrategy::print(TreeNode* node, int level = 1)
{
    TreeNode* tmp = node;

    if (tmp->left != NULL) {
        int leftLevel = level + 1;
        std::cout << std::string(level, ' ') << "Left child of node: " << tmp->left->data << std::endl;
        print(tmp->left, leftLevel);
    }

    if (tmp->right != NULL) {
        int rightLevel = level + 1;
        std::cout << std::string(level, ' ') << "Right child of node: " << tmp->right->data << std::endl;
        print(tmp->right, rightLevel);
    }
}

TreeNode* RecursiveTreeStrategy::search(TreeNode* node, int data)
{
    TreeNode* resultNode = NULL;
    if (node == NULL || node->data == data) {
        resultNode = node;
    } else if (node->data < data) {
        resultNode = search(node->right, data);
    } else if (node->data > data) {
        resultNode = search(node->left, data);
    }
    return resultNode;
}

TreeNode* RecursiveTreeStrategy::erase(TreeNode* node, int data)
{
    if (data < node->data) {
        node->left = erase(node->left, data);
    } else if (data > node->data) {
        node->right = erase(node->right, data);
    } else {
        TreeNode* tmp;
        if (node->left == NULL) {
            tmp = node->right;
            delete node;
            return tmp;
        } else if (node->right == NULL) {
            tmp = node->left;
            delete node;
            return tmp;
        }
        tmp = minValueNode(node->right);
        node->data = tmp->data;
        node->right = erase(node->right, tmp->data);
    }
    return node;
}

TreeNode* RecursiveTreeStrategy::minValueNode(TreeNode* node)
{
    TreeNode* current = node;
    while (current->left != NULL) {
        current = current->left;
    }
    return current;
}
