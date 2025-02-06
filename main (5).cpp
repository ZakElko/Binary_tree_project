/******************************************************************************
 Zakaria Elkhodary
 CISC 187 Chapter 21 Programming Assignment
 12/4/2024
*******************************************************************************/
#include <iostream>
#include <limits>
#include "BinaryTree.h"

using namespace std;

// Function to validate integer input
int getValidatedInt() {
    int value;
    while (true) {
        cin >> value;
        if (cin.fail()) {
            cout << "Try Again. Please enter a valid integer: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return value;
        }
    }
}

// Function to validate menu choice
int getValidatedChoice() {
    int choice;
    while (true) {
        choice = getValidatedInt();
        if (choice >= 1 && choice <= 6) {
            return choice;
        } else {
            cout << "Thats not gonna work with me, Please enter a number between 1 and 6: ";
        }
    }
}

int main() {
    BinaryTree<int> tree;
    int choice, value;

    do {
        cout << "\nMenu:\n"
             << "1. Insert an integer into the tree\n"
             << "2. Display the tree in order\n"
             << "3. Display leaf count\n"
             << "4. Display tree height\n"
             << "5. Display tree width\n"
             << "6. Exit\n"
             << "Enter your choice: ";
        choice = getValidatedChoice();

        switch (choice) {
            case 1:
                cout << "Enter an int that you would like to insert: ";
                value = getValidatedInt();
                tree.insertNode(value);
                cout << "awwlrighty! we Inserted: " << value << " into the tree.\n";
                break;
            case 2:
                cout << "Tree in order: ";
                tree.displayInOrder();
                cout << endl;
                break;
            case 3:
                cout << "Leaf count: " << tree.getLeafCount() << endl;
                break;
            case 4:
                cout << "Tree height: " << tree.getHeight() << endl;
                break;
            case 5:
                cout << "Tree width: " << tree.getWidth() << endl;
                break;
            case 6:
                cout << "Exiting program.\n";
                break;
        }
    } while (choice != 6);

    return 0;
}
