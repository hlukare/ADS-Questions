/*
Problem Statement: Expression tree: Write a menu driven C++ program to construct an expression tree from the given prefix expression eg. +--a*bc/def and 
            perform following operations:
                1. Traverse it using post order traversal (non recursive) 
                2. Delete the entire tree 
                3. Change a tree so that the roles of the left and right pointers are +swapped at every node
*/

#include <iostream>
#include <stack>

using namespace std;

struct Node {
    char data;
    Node* left;
    Node* right;

    Node(char val) : data(val), left(nullptr), right(nullptr) {}
};


Node* constructTree(string prefix) 
{
    stack<Node*> st;
   
    for (int i = prefix.size() - 1; i >= 0; i--) 
    {
        char ch = prefix[i];

        if (isalnum(ch)) 
          {
            st.push(new Node(ch));
          } 
        else 
          {
            Node* temp = new Node(ch);
            temp->right = st.top();
            st.pop();
            temp->left = st.top();
            st.pop();
            st.push(temp);
          }
    }
    return st.top();
}

void postorderTraversal(Node* root) 
{
    if (root == nullptr) 
      {
        return;
      }

    stack<Node*> s1, s2;
    s1.push(root);

    while (!s1.empty()) 
    {
        Node* temp = s1.top();
        s1.pop();
        s2.push(temp);

        if (temp->left) 
          {
            s1.push(temp->left);
          }
        if (temp->right) 
          {
            s1.push(temp->right);
          }
    }

    while (!s2.empty()) 
      {
        cout << s2.top()->data << " ";
        s2.pop();
      }
    cout << endl;
}

void deleteTree(Node* root) 
{
    if (root == nullptr) {
        return;
    }

    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

void swapPointers(Node* root) 
{
    if (root == nullptr) {
        return;
    }

    Node* temp = root->left;
    root->left = root->right;
    root->right = temp;

    swapPointers(root->left);
    swapPointers(root->right);
}

int main() {
    string prefixExpr;
    cout << "Enter a prefix expression: ";
    cin >> prefixExpr;

    Node* root = constructTree(prefixExpr);

    int choice;
    do {
        cout << "\nMenu:" << endl;
        cout << "1. Traverse using postorder traversal (non-recursive)" << endl;
        cout << "2. Delete the entire tree" << endl;
        cout << "3. Swap left and right pointers" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                postorderTraversal(root);
                break;
            case 2:
                deleteTree(root);
                root = nullptr;
                cout << "Tree deleted." << endl;
                break;
            case 3:
                swapPointers(root);
                cout << "Left and right pointers swapped." << endl;
                break;
            case 4:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice." << endl;
        }
    } while (choice != 4);

    return 0;
}

/*
Output: Enter a prefix expression: +ab

Menu:
1. Traverse using postorder traversal (non-recursive)
2. Delete the entire tree
3. Swap left and right pointers
4. Exit
Enter your choice: 1
b a + 

Menu:
1. Traverse using postorder traversal (non-recursive)
2. Delete the entire tree
3. Swap left and right pointers
4. Exit
Enter your choice: 3
Left and right pointers swapped.

Menu:
1. Traverse using postorder traversal (non-recursive)
2. Delete the entire tree
3. Swap left and right pointers
4. Exit
Enter your choice: 1
a b +

Menu:
1. Traverse using postorder traversal (non-recursive)
2. Delete the entire tree
3. Swap left and right pointers
4. Exit
Enter your choice: 4
Exiting...
*/