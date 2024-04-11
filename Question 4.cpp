/*
Problem Statement : Binary search tree: Write a menu driven C++ program to construct a binary search tree by inserting the values in the order give, considering at 
              the beginning with an empty binary search tree, After constructing a binary tree. Insert new node, ii. Find number of nodes in longest path from root, iii. 
              Minimum data value found in the tree iv. Search a value v. Print values in ascending and descending order
*/

#include <iostream>

using namespace std;

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int data) : data(data), left(nullptr), right(nullptr) {}
};

TreeNode* root = nullptr;

void insertNode(int value) 
{
  if (root == nullptr) 
    {
      root = new TreeNode(value);
      return;
    }

  TreeNode* current = root;
  while (true) 
  {
    if (value < current->data) 
      {
        if (current->left == nullptr) 
          {
            current->left = new TreeNode(value);
            return;
          }
        current = current->left;
      } 
    else
      {
        if (current->right == nullptr) 
          {
            current->right = new TreeNode(value);
            return;
          }
      current = current->right;
      }
  }
}

int findLongestPathLength(TreeNode* root) 
{
  if (root == nullptr) 
    {
      return 0;
    }

  int leftLength = findLongestPathLength(root->left);
  int rightLength = findLongestPathLength(root->right);

  return max(leftLength, rightLength) + 1;
}

int findMin(TreeNode* root) {
    if (root == nullptr) {
        return -1; // Or any other value to indicate an empty tree
    }

    while (root->left != nullptr) 
      {
        root = root->left;
      }

    return root->data;
}

bool searchNode(int value) 
{
  TreeNode* current = root;
  while (current != nullptr) 
  {
    if (value == current->data)  
      {
        return true;
      } 
  
    else if (value < current->data) 
      {
        current = current->left;
      } 

    else 
      {
        current = current->right;
      }
  }

  return false;
}

void printInorder(TreeNode* root) 
{
  if (root != nullptr)      
   {
      printInorder(root->left);
      cout << root->data << " ";
      printInorder(root->right);
   }
}

void printPostorder(TreeNode* root) 
{
  if (root != nullptr) 
  {
    printPostorder(root->left);
    printPostorder(root->right);
    cout << root->data << " ";
  }
}

int main() {
    int choice, value;

    while (true) 
    {
        cout << "\nBinary Search Tree Menu:\n";
        cout << "1. Insert new node\n";
        cout << "2. Find longest path length\n";
        cout << "3. Find minimum value\n";
        cout << "4. Search a value\n";
        cout << "5. Print in ascending order (inorder)\n";
        cout << "6. Print in descending order (postorder)\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> value;
                insertNode(value);
                break;

            case 2:
                cout << "Longest path length: " << findLongestPathLength(root) << endl;
                break;

           case 3:
            if (root != nullptr) 
              {
                cout << "Minimum value: " << findMin(root) << endl;
              } 
            else 
              {
                cout << "Error: Empty tree." << endl;
              }
            break;

            case 4:
                cout << "Enter value to search: ";
                cin >> value;
                if (searchNode(value)) {
                    cout << "Value found in the tree." << endl;
                } 
                else {
                    cout << "Value not found in the tree." << endl;
                }
                break;

            case 5:
                cout << "Values in ascending order: ";
                printInorder(root);
                cout << endl;
                break;

            case 6:
                cout << "Values in descending order: ";
                printPostorder(root);
                cout << endl;
                break;

            case 7:
                exit(0);
            default:
                cout << "Invalid choice!\n";
        }
    }
    return 0;
}

/*
Output: Binary Search Tree Menu:
1. Insert new node
2. Find longest path length
3. Find minimum value
4. Search a value
5. Print in ascending order (inorder)
6. Print in descending order (postorder)
7. Exit
Enter your choice: 1
Enter value to insert: 12

Binary Search Tree Menu:
1. Insert new node
2. Find longest path length
3. Find minimum value
4. Search a value
5. Print in ascending order (inorder)
6. Print in descending order (postorder)
7. Exit
Enter your choice: 1
Enter value to insert: 24

Binary Search Tree Menu:
1. Insert new node
2. Find longest path length
3. Find minimum value
4. Search a value
5. Print in ascending order (inorder)
6. Print in descending order (postorder)
7. Exit
Enter your choice: 1
Enter value to insert: 56

Binary Search Tree Menu:
1. Insert new node
2. Find longest path length
3. Find minimum value
4. Search a value
5. Print in ascending order (inorder)
6. Print in descending order (postorder)
7. Exit
Enter your choice: 1
Enter value to insert: 2

Binary Search Tree Menu:
1. Insert new node
2. Find longest path length
3. Find minimum value
4. Search a value
5. Print in ascending order (inorder)
6. Print in descending order (postorder)
7. Exit
Enter your choice: 1
Enter value to insert: 98

Binary Search Tree Menu:
1. Insert new node
2. Find longest path length
3. Find minimum value
4. Search a value
5. Print in ascending order (inorder)
6. Print in descending order (postorder)
7. Exit
Enter your choice: 1
Enter value to insert: 45

Binary Search Tree Menu:
1. Insert new node
2. Find longest path length
3. Find minimum value
4. Search a value
5. Print in ascending order (inorder)
6. Print in descending order (postorder)
7. Exit
Enter your choice: 1
Enter value to insert: 0

Binary Search Tree Menu:
1. Insert new node
2. Find longest path length
3. Find minimum value
4. Search a value
5. Print in ascending order (inorder)
6. Print in descending order (postorder)
7. Exit
Enter your choice: 1
Enter value to insert: 1

Binary Search Tree Menu:
1. Insert new node
2. Find longest path length
3. Find minimum value
4. Search a value
5. Print in ascending order (inorder)
6. Print in descending order (postorder)
7. Exit
Enter your choice: 1
Enter value to insert: 36

Binary Search Tree Menu:
1. Insert new node
2. Find longest path length
3. Find minimum value
4. Search a value
5. Print in ascending order (inorder)
6. Print in descending order (postorder)
7. Exit
Enter your choice: 2
Longest path length: 5

Binary Search Tree Menu:
1. Insert new node
2. Find longest path length
3. Find minimum value
4. Search a value
5. Print in ascending order (inorder)
6. Print in descending order (postorder)
7. Exit
Enter your choice: 5
Values in ascending order: 0 1 2 12 24 36 45 56 98

Binary Search Tree Menu:
1. Insert new node
2. Find longest path length
3. Find minimum value
4. Search a value
5. Print in ascending order (inorder)
6. Print in descending order (postorder)
7. Exit
Enter your choice: 4
Enter value to search: 3
Value not found in the tree.

Binary Search Tree Menu:
1. Insert new node
2. Find longest path length
3. Find minimum value
4. Search a value
5. Print in ascending order (inorder)
6. Print in descending order (postorder)
7. Exit
Enter your choice: 3
Minimum value: 0

Binary Search Tree Menu:
1. Insert new node
2. Find longest path length
3. Find minimum value
4. Search a value
5. Print in ascending order (inorder)
6. Print in descending order (postorder)
7. Exit
Enter your choice: 6
Values in descending order: 1 0 2 36 45 98 56 24 12

Binary Search Tree Menu:
1. Insert new node
2. Find longest path length
3. Find minimum value
4. Search a value
5. Print in ascending order (inorder)
6. Print in descending order (postorder)
7. Exit
Enter your choice: 7
*/