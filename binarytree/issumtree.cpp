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

pair<bool, int> isSum(node *root)
{ 
    //base case
    if (root == NULL)
    {
        pair<int, int> p = make_pair(true, 0);
        return p;
    }
    if(root->left ==NULL && root->right == NULL){
       pair<int, int> p = make_pair(true, root->data);
        return p;
    }

    pair<bool, int> left = isSum(root->left);
    pair<bool, int> right = isSum(root->right);

    bool option1 = left.first;
    bool option2 = right.first;
    bool option3 = root->data == left.second + right.second ;
    
    pair<bool,int>ans;
    
    if(option1 && option2 && option3){
        ans.first = true;
        ans.second = 2*root->data;
        }
    else{
        ans.first =  false;}

    return ans;
}
bool issumtree(node*root){


    return isSum(root).first;
}
int main()
{
    // Creating a binary tree
    struct node *root = new node(26);
    root->left = new node(10);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(6);
    root->right->right = new node(3);

    // Check if the binary tree is a Sum Tree
    bool isSumTreeResult = issumtree(root);

    if (isSumTreeResult)
    {
        cout << "The binary tree is a Sum Tree." << endl;
    }
    else
    {
        cout << "The binary tree is not a Sum Tree." << endl;
    }

    return 0;
}
