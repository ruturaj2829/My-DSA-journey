#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <map>
using namespace std;
struct node
{
    int data ;
    struct node*left;
    struct node*right;
    node(int x){
        data  = x;
        left = right = NULL;
    }
};
void flatten(node*root){

    node*curr = root;
    while(curr!=NULL){

        if(curr->left){

            node*pred = curr->left;
            while(pred->right!=NULL){
                pred =pred->right;

                pred->right = curr->right;
                curr->right = curr->left;
                curr->left = NULL;
            }
        }
        curr = curr->right;
    }
    
}
int main() {
    // Creating a binary tree
    node* root = new node(1);
    root->left = new node(2);
    root->right = new node(5);
    root->left->left = new node(3);
    root->left->right = new node(4);
    root->right->right = new node(6);

    cout << "Original Binary Tree:" << endl;
    // Print the original binary tree
    // You can implement a tree traversal function to print it in a meaningful way
    // For simplicity, let's just print the flattened tree
    flatten(root);

    cout << "Flattened Binary Tree:" << endl;
    // Print the flattened binary tree
    // You can implement a tree traversal function to print it in a meaningful way
    // For simplicity, let's just print the flattened tree
    node* curr = root;
    while (curr != NULL) {
        cout << curr->data << " ";
        curr = curr->right;
    }

    return 0;
}

