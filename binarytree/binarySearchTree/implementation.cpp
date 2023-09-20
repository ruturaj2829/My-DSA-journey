#include <iostream>
using namespace std;

struct node {
    int data;
    struct node* left;
    struct node* right;
    node(int x) {
        data = x;
        left = right = NULL;
    }
};

node* insert(node* root, int data) {
    if (root == NULL) {
        return new node(data);
    }
    if (data <= root->data) {
        root->left = insert(root->left, data);
    } else {
        root->right = insert(root->right, data);
    }
    return root;  // Return the modified root after insertion
}

void takeInput(node*& root) {
    int data;
    cin >> data;
    while (data != -1) {
        root = insert(root, data);
        cin >> data;
    }
}

void inorderTraversal(node* root) {
    if (root == NULL) {
        return;
    }
    inorderTraversal(root->left);
    cout << root->data << " ";
    inorderTraversal(root->right);
}
void preorderTraversal(node* root) {
    if (root == NULL) {
        return;
    }
    cout << root->data << " ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}
void postorderTraversal(node* root) {
    if (root == NULL) {
        return;
    }
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    cout << root->data << " ";
}

int main() {
    node* root = NULL;  // Initialize the root pointer as NULL
    cout << "Enter values to create a binary search tree (-1 to stop):" << endl;
    takeInput(root);

    cout << "Inorder traversal of the binary search tree:" << endl;
    inorderTraversal(root);
     
    cout << "\nPreorder traversal of the binary search tree:" << endl;
    preorderTraversal(root);

    cout << "\nPostorder traversal of the binary search tree:" << endl;
    postorderTraversal(root);

    return 0;
}
