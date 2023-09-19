#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <map>
using namespace std;

struct node
{
    int data;
    struct node* left;
    struct node* right;
    node(int x) {
        data = x;
        left = right = NULL;
    }
};

node* lca(node* root, int n1, int n2) {
    if (root == NULL) {
        return NULL;
    }

    if (root->data == n1 || root->data == n2) {
        return root;
    }

    node* leftans = lca(root->left, n1, n2);
    node* rightans = lca(root->right, n1, n2);

    if (leftans != NULL && rightans != NULL) {
        return root;
    }

    return (leftans != NULL) ? leftans : rightans;
}

int main() {
    // Creating a binary tree
    struct node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    // root->left->right = new node(5);
    // root->right->left = new node(6);
    // root->right->right = new node(7);

    // Call the lca function to find the Lowest Common Ancestor
    node* ans = lca(root, 4, 3);

    // Print the Lowest Common Ancestor
    if (ans != NULL) {
        cout << "Lowest Common Ancestor is: " << ans->data;
    } else {
        cout << "Lowest Common Ancestor not found";
    }

    return 0;
}
