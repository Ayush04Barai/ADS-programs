/*
    Name :- AYUSH BARAI
    Roll No:- 06
    Assignment 4
    SY CSD

        Problem Statement:
                Binary search tree: Write a menu driven C++ program to construct a
                                    binary search tree by inserting the values in the order give, considering at
                                    the beginning with an empty binary search tree,  After constructing a
                                    binary tree-
                                    i. Insert new node, ii. Find number of nodes in longest path from root, iii.
                                    Minimum data value found in the tree  iv. Search a value v. Print values
                                    in ascending and descending order.

*/

#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

class BinaryTree
{
private:
    Node *root;

public:
    BinaryTree() : root(nullptr) {}

    void insert(int value)
    {
        root = insertRecursive(root, value);
    }

    Node *insertRecursive(Node *root, int value)
    {
        if (root == nullptr)
        {
            return new Node(value);
        }

        if (value < root->data)
        {
            root->left = insertRecursive(root->left, value);
        }
        else if (value > root->data)
        {
            root->right = insertRecursive(root->right, value);
        }

        return root;
    }

    void inorderTraversal(Node *root)
    {
        if (root == nullptr)
        {
            return;
        }
        inorderTraversal(root->left);
        cout << root->data << " ";
        inorderTraversal(root->right);
    }

    void printTree()
    {
        cout << "Inorder Traversal: ";
        inorderTraversal(root);
        cout << endl;
    }

    void search(int key)
    {
        searchRecursive(root, key);
    }

    void searchRecursive(Node *root, int key)
    {
        if (root == nullptr)
        {
            cout << "Node not found" << endl;
            return;
        }
        if (root->data == key)
        {
            cout << "Node found" << endl;
            return;
        }
        else if (key < root->data)
        {
            searchRecursive(root->left, key);
        }
        else
        {
            searchRecursive(root->right, key);
        }
    }

    int countNodesLongestPath()
    {
        return countNodesLongestPathHelper(root);
    }

    int countNodesLongestPathHelper(Node *node)
    {
        if (node == nullptr)
        {
            return 0;
        }
        int leftHeight = countNodesLongestPathHelper(node->left);
        int rightHeight = countNodesLongestPathHelper(node->right);
        return 1 + max(leftHeight, rightHeight);
    }

    int findMinValue()
    {
        if (root == nullptr)
        {
            cout << "Tree is empty." << endl;
            return 0; // or throw an exception
        }
        return findMinValueHelper(root);
    }

    int findMinValueHelper(Node *node)
    {
        if (node->left == nullptr)
        {
            return node->data;
        }
        return findMinValueHelper(node->left);
    }

    Node *getRoot() const
    {
        return root;
    }
    void reverseInorderTraversal(Node *root)
    {
        if (root == nullptr)
        {
            return;
        }
        reverseInorderTraversal(root->right);
        cout << root->data << " ";
        reverseInorderTraversal(root->left);
    }

    void printAscending()
    {
        cout << "Values in ascending order: ";
        inorderTraversal(root);
        cout << endl;
    }

    void printDescending()
    {
        cout << "Values in descending order: ";
        reverseInorderTraversal(root);
        cout << endl;
    }
};

int main()
{
    BinaryTree tree;
    int choice, key, value;

    do
    {
        cout << "1. Insert\n";
        cout << "2. Print Tree\n";
        cout << "3. Search\n";
        cout << "4. Count Nodes in Longest Path\n";
        cout << "5. Find Minimum Value\n";
        cout << "6. Print Ascending\n";
        cout << "7. Print Descending\n";
        cout << "8. Exit\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter the key to insert in the tree: ";
            cin >> value;
            tree.insert(value);
            break;
        case 2:
            tree.printTree();
            break;
        case 3:
            cout << "Enter the key element to search in the tree: ";
            cin >> key;
            tree.search(key);
            break;
        case 4:
            cout << "Number of nodes in the longest path from root: " << tree.countNodesLongestPath() << endl;
            break;
        case 5:
            cout << "Minimum data value found in the tree: " << tree.findMinValue() << endl;
            break;
        case 6:
            tree.printAscending();
            break;
        case 7:
            tree.printDescending();
            break;
        case 8:
            cout << "Exiting program...\n";
            exit(0);
            break;
        default:
            cout << "Invalid choice. Please enter a number between 1 and 8.\n";
        }
    } while (choice != 0);

    return 0;
}

/*

1. Insert
2. Print Tree
3. Search
4. Count Nodes in Longest Path
5. Find Minimum Value
6. Print Ascending
7. Print Descending
8. Exit
Enter your choice: 1
Enter the key to insert in the tree: 3
1. Insert
2. Print Tree
3. Search
4. Count Nodes in Longest Path
5. Find Minimum Value
6. Print Ascending
7. Print Descending
8. Exit
Enter your choice: 1
Enter the key to insert in the tree: 1
1. Insert
2. Print Tree
3. Search
4. Count Nodes in Longest Path
5. Find Minimum Value
6. Print Ascending
7. Print Descending
8. Exit
Enter your choice: 1
Enter the key to insert in the tree: 2
1. Insert
2. Print Tree
3. Search
4. Count Nodes in Longest Path
5. Find Minimum Value
6. Print Ascending
7. Print Descending
8. Exit
Enter your choice: 1
Enter the key to insert in the tree: 4
1. Insert
2. Print Tree
3. Search
4. Count Nodes in Longest Path
5. Find Minimum Value
6. Print Ascending
7. Print Descending
8. Exit
Enter your choice: 1
Enter the key to insert in the tree: 6
1. Insert
2. Print Tree
3. Search
4. Count Nodes in Longest Path
5. Find Minimum Value
6. Print Ascending
7. Print Descending
8. Exit
Enter your choice: 1
Enter the key to insert in the tree: 7
1. Insert
2. Print Tree
3. Search
4. Count Nodes in Longest Path
5. Find Minimum Value
6. Print Ascending
7. Print Descending
8. Exit
Enter your choice: 2
Inorder Traversal: 1 2 3 4 6 7
1. Insert
2. Print Tree
3. Search
4. Count Nodes in Longest Path
5. Find Minimum Value
6. Print Ascending
7. Print Descending
8. Exit
Enter your choice: 3
Enter the key element to search in the tree: 4
Node found
1. Insert
2. Print Tree
3. Search
4. Count Nodes in Longest Path
5. Find Minimum Value
6. Print Ascending
7. Print Descending
8. Exit
Enter your choice: 3
Enter the key element to search in the tree: 9
Node not found
1. Insert
2. Print Tree
3. Search
4. Count Nodes in Longest Path
5. Find Minimum Value
6. Print Ascending
7. Print Descending
8. Exit
Enter your choice: 4
Number of nodes in the longest path from root: 4
1. Insert
2. Print Tree
3. Search
4. Count Nodes in Longest Path
5. Find Minimum Value
6. Print Ascending
7. Print Descending
8. Exit
Enter your choice: 5
Minimum data value found in the tree: 1
1. Insert
2. Print Tree
3. Search
4. Count Nodes in Longest Path
5. Find Minimum Value
6. Print Ascending
7. Print Descending
8. Exit
Enter your choice: 6
Values in ascending order: 1 2 3 4 6 7
1. Insert
2. Print Tree
3. Search
4. Count Nodes in Longest Path
5. Find Minimum Value
6. Print Ascending
7. Print Descending
8. Exit
Enter your choice: 7
Values in descending order: 7 6 4 3 2 1
1. Insert
2. Print Tree
3. Search
4. Count Nodes in Longest Path
5. Find Minimum Value
6. Print Ascending
7. Print Descending
8. Exit
Enter your choice: 8
Exiting program...

*/
