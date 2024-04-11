/*
Problem Statement: Tree using traversal sequence: Write a C++ program to construct the binary tree with a given preorder and inorder sequence and Test your tree 
with all traversals
*/

#include <iostream>

using namespace std;

struct Node {
  int data;
  Node* left;
  Node* right;

  Node(int x) {
    data = x;
    left = nullptr;
    right = nullptr;
  }
};

int findIndex(int inOrder[], int value, int size) {
  for (int i = 0; i < size; i++) {
    if (inOrder[i] == value) {
      return i;
    }
  }
  return -1;
}

Node* constructTree(int inOrder[], int preOrder[], int inStart, int inEnd, int* preIndex) 
{
  if (inStart > inEnd) 
    {
      return nullptr;
    }

  Node* root = new Node(preOrder[*preIndex]);
  (*preIndex)++;

  int inIndex = findIndex(inOrder, root->data, inEnd + 1);

  root->left = constructTree(inOrder, preOrder, inStart, inIndex - 1, preIndex);
  root->right = constructTree(inOrder, preOrder, inIndex + 1, inEnd, preIndex);

  return root;
}

void preorderTraversal(Node* root) {
  if (root == nullptr) {
    return;
  }

  cout << root->data << " ";
  preorderTraversal(root->left);
  preorderTraversal(root->right);
}

void inorderTraversal(Node* root) {
  if (root == nullptr) {
    return;
  }

  inorderTraversal(root->left);
  cout << root->data << " ";
  inorderTraversal(root->right);
}

void postorderTraversal(Node* root) {
  if (root == nullptr) {
    return;
  }

  postorderTraversal(root->left);
  postorderTraversal(root->right);
  cout << root->data << " ";
}

int main() {
  int size;
  cout << "Enter the size of the binary tree: ";
  cin >> size;

  int inOrder[size], preOrder[size];

  cout << "Enter the inorder traversal (space-separated integers): ";
  for (int i = 0; i < size; i++) {
    cin >> inOrder[i];
  }

  cout << "Enter the preorder traversal (space-separated integers): ";
  for (int i = 0; i < size; i++) {
    cin >> preOrder[i];
  }

  int preIndex = 0;
  Node* root = constructTree(inOrder, preOrder, 0, size - 1, &preIndex);

  cout << "Binary tree constructed successfully!" << endl;

  int choice;
  do {
    cout << "\nMenu:\n";
    cout << "1. Preorder Traversal\n";
    cout << "2. Inorder Traversal\n";
    cout << "3. Postorder Traversal\n";
    cout << "4. Exit\n";
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice) {
      case 1:
        cout << "Preorder traversal: ";
        preorderTraversal(root);
        cout << endl;
        break;
      case 2:
        cout << "Inorder traversal: ";
        inorderTraversal(root);
        cout << endl;
        break;
      case 3:
        cout << "Postorder traversal: ";
        postorderTraversal(root);
        cout << endl;
        break;
      case 4:
        cout << "Exiting..." << endl;
        break;
      default:
        cout << "Invalid choice. Please enter valid choice."<<endl;
        break;
    }

    }while(choice != 4);

  return 0;
}

/*
Output: Enter the size of the binary tree: 9
Enter the inorder traversal (space-separated integers): 7 9 4 2 5 1 3 6 8
Enter the preorder traversal (space-separated integers): 1 2 4 7 9 5 3 6 8
Binary tree constructed successfully!

Menu:
1. Preorder Traversal
2. Inorder Traversal
3. Postorder Traversal
4. Exit
Enter your choice: 1
Preorder traversal: 1 2 4 7 9 5 3 6 8 

Menu:
1. Preorder Traversal
2. Inorder Traversal
3. Postorder Traversal
4. Exit
Enter your choice: 2
Inorder traversal: 7 9 4 2 5 1 3 6 8

Menu:
1. Preorder Traversal
2. Inorder Traversal
3. Postorder Traversal
4. Exit
Enter your choice: 3
Postorder traversal: 9 7 4 5 2 8 6 3 1

Menu:
1. Preorder Traversal
2. Inorder Traversal
3. Postorder Traversal
4. Exit
Enter your choice: 4
Exiting...
*/