//optimal
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

pair<bool, int> isbalancedn(node *root)
{
    if (root == NULL)
    {
        pair<int, int> p = make_pair(true, 0);
        return p;
    }

    pair<int, int> left = isbalancedn(root->left);
    pair<int, int> right = isbalancedn(root->right);

    int option1 = left.first;
    int option2 = right.first;
    int option3 = abs(left.second - right.second )<=1;
    
    pair<bool,int>ans;
    ans.second  = max(left.second,right.second)+1;
    if(option1&&option2&&option3){
        ans.first = true;
        }
    else{
        ans.first =  false;}

    return ans;
}

bool isbalanced(node* root){

    return isbalancedn(root).first;

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
