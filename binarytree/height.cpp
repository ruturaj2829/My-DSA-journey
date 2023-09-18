#include <iostream>
#include <stack>
#include <queue>
#include <vector>
struct node
{
    int data;
    struct node *left;
    struct node *right;
    node(int x)
    {
        data = x;
        left = right = NULL;
    }
};
using namespace std;

int height(struct node *node)
{
    if (node == NULL)
    {
        return 0;
    }
    int left = height(node->left);
    int right = height(node->right);
    int ans = max(left, right) + 1;
    return ans;
}

int main()
{
    // Creating a binary tree
    struct node *root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);

    // Calculate and print the height of the tree
    int treeHeight = height(root);
    cout << "Height of the binary tree is: " << treeHeight << endl;

    return 0;
}
