#ifndef BINARYTREE_H
#define BINARYTREE_H

#include <iostream>
using namespace std;

// BinaryTree template:
template <class T>
class BinaryTree {
private:
    struct TreeNode {
        T value;
        TreeNode* left;
        TreeNode* right;
    };

    TreeNode* root;

    // Private member functions:
    void insert(TreeNode*&, TreeNode*&);
    void destroySubTree(TreeNode*);
    void displayInOrder(TreeNode*) const;
    int countLeaves(TreeNode*) const;
    int calculateHeight(TreeNode*) const;
    int calculateWidth(TreeNode*, int) const;

public:
    // Constructor initalizing the root pointer 
    BinaryTree() { root = nullptr; }

    // Destructor 
    ~BinaryTree() { destroySubTree(root); }

    // Binary tree operations:
    void insertNode(T);
    void displayInOrder() const { displayInOrder(root); }
    int getLeafCount() const { return countLeaves(root); }
    int getHeight() const { return calculateHeight(root); }
    int getWidth();
};

#endif
