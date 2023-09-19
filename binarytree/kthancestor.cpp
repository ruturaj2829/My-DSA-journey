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
    node(int x) : data(x), left(nullptr), right(nullptr) {}
};

node* solve(node* root, int& k, int target) {
    if (root == nullptr) {
        return nullptr;
    }

    if (root->data == target || kthancestor(root->left, k, target) || kthancestor(root->right, k, target)) {
        if (k > 0) {
            k--;
            if (k == 0) {
                cout << "Kth ancestor = " << root->data << endl;
            }
        }
        return root;
    }

    return nullptr;
}

int kthancestor(node* root, int k, int node) {
    if (root == nullptr) {
        return -1;
    }

    solve(root, k, node);

    // If k is still greater than 0, it means there are less than k ancestors.
    if (k > 0) {
        return -1;
    }

    return 0;
}

int main() {
    // Creating a binary tree
    struct node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(-4);
    root->left->right = new node(-5);
    root->right->left = new node(6);
    root->right->right = new node(7);

    int k = 2;
    int node = 7;
    kthancestor(root, k, node);
    return 0;
}
