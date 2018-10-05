#include <iostream>
#include <vector>
#include <stdlib.h>

using namespace std;

enum TreeFlag {
    RED,
    BLACK
};

struct TreeNode
{
    int data;
    TreeFlag color;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
        color = TreeFlag::RED;
    }
};

class TreeStrategy
{
protected:
    TreeStrategy() {};
public:
    virtual TreeNode* insert(TreeNode* root, int data) = 0;
    virtual void print(TreeNode* root, int level) = 0;
    virtual TreeNode* search(TreeNode* root, int data) = 0;
};

class RecursiveTreeStrategy : public TreeStrategy
{
public:
    RecursiveTreeStrategy()
    {

    }

    TreeNode* insert(TreeNode* node, int data)
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

    void print(TreeNode* node, int level = 1)
    {
        TreeNode* tmp = node;

        if (tmp->left != NULL) {
            int leftLevel = level + 1;
            cout << string(level, ' ') << "Left child of node: " << tmp->left->data << endl;
            print(tmp->left, leftLevel);
        }

        if (tmp->right != NULL) {
            int rightLevel = level + 1;
            cout << string(level, ' ') << "Right child of node: " << tmp->right->data << endl;
            print(tmp->right, rightLevel);
        }
    }

    TreeNode* search(TreeNode* node, int data)
    {
        TreeNode* resultNode = NULL;
        if (node == NULL || node->data == data) {
            resultNode = node;
        }

        if (node->data < data) {
            resultNode = search(node->right, data);
        } else if (node->data > data) {
            resultNode = search(node->left, data);
        }
        return resultNode;
    }
};

class BSTree
{
    TreeNode* root;
    TreeStrategy* strategy;
public:
    BSTree()
    {
        root = NULL;
        strategy = new RecursiveTreeStrategy();
    }

    void print()
    {
        strategy->print(root, 1);
    }

    void insert(int data)
    {
        root = strategy->insert(root, data);
    }

    bool search(int data)
    {
        TreeNode* node = strategy->search(root, data);
        return node != NULL && data == node->data;
    }
};

int main()
{
    BSTree tree;
    for(int i = 0; i < 20; i++) {
        tree.insert(rand() % 20);
    }
    tree.print();
    int number = 9;
    cout << "Number " << number << " " << (tree.search(number)? "found" : "not found") << endl;
    return 0;
}
