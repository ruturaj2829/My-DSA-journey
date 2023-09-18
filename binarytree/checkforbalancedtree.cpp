//brut force app
#include <iostream>
#include <stack>
#include <queue>
#include <vector>
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
bool isbalanced(node* root){

    if(root==NULL){
        return true;
    }
    bool left,right,all;
    left = isbalanced(root->left);
    right = isbalanced(root->right);
    all = abs(height(root->left)-height(root->right)) <=1;

    if(left&&right&&all)return true;
    else{return false;}

}
int main()
{
    // Creating a binary tree
    struct node *root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->left->left->left = new node(6); // Uncomment to make it unbalanced

    // Check if the binary tree is balanced
    bool balanced = isbalanced(root);

    if (balanced)
    {
        cout << "The binary tree is balanced." << endl;
    }
    else
    {
        cout << "The binary tree is not balanced." << endl;
    }

    return 0;
}
