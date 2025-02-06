#include "BinaryTree.h"
#include <algorithm>

// Functioon to insert node. 
template <class T>
void BinaryTree<T>::insert(TreeNode*& nodePtr, TreeNode*& newNode) {
    if (nodePtr == nullptr)
        nodePtr = newNode;
    else if (newNode->value < nodePtr->value)
        insert(nodePtr->left, newNode);
    else
        insert(nodePtr->right, newNode);
}


//  The insertnode function creates a new node and calls insert().
template <class T>
void BinaryTree<T>::insertNode(T item) {
    TreeNode* newNode = new TreeNode;
    newNode->value = item;
    newNode->left = newNode->right = nullptr;
    insert(root, newNode);
}

// The destroySubTree function deletes all nodes.
template <class T>
void BinaryTree<T>::destroySubTree(TreeNode* nodePtr) {
    if (nodePtr) {
        destroySubTree(nodePtr->left);
        destroySubTree(nodePtr->right);
        delete nodePtr;
    }
}

// The displayInOrder function displays the elements in order.
template <class T>
void BinaryTree<T>::displayInOrder(TreeNode* nodePtr) const {
    if (nodePtr) {
        displayInOrder(nodePtr->left);
        cout << nodePtr->value << " ";
        displayInOrder(nodePtr->right);
    }
}

// The countLeaves function counts the leaf nodes.
template <class T>
int BinaryTree<T>::countLeaves(TreeNode* nodePtr) const {
    if (!nodePtr) return 0;
    if (!nodePtr->left && !nodePtr->right) return 1;
    return countLeaves(nodePtr->left) + countLeaves(nodePtr->right);
}

// The calculateHeight function calculates the height of the tree.
template <class T>
int BinaryTree<T>::calculateHeight(TreeNode* nodePtr) const {
    if (!nodePtr) return -1;
    return 1 + max(calculateHeight(nodePtr->left), calculateHeight(nodePtr->right));
}

// The getWidth function calculates the max width of the tree.
template <class T>
int BinaryTree<T>::getWidth() {
    int maxWidth = 0, height = getHeight();
    for (int level = 0; level <= height; level++) {
        int width = calculateWidth(root, level);
        maxWidth = max(maxWidth, width);
    }
    return maxWidth;
}

// The calculateWidth function calculates the width of a specific level. 
template <class T>
int BinaryTree<T>::calculateWidth(TreeNode* nodePtr, int level) const {
    if (!nodePtr) return 0;
    if (level == 0) return 1;
    return calculateWidth(nodePtr->left, level - 1) + calculateWidth(nodePtr->right, level - 1);
}

template class BinaryTree<int>;
