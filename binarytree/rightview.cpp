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
void solve (node* root , vector<int>&ans , int level){

    if(root==NULL){
        return;
    }
    if(ans.size()==level){
        ans.push_back(root->data);
        solve(root->right,ans,level+1);
        solve(root->left,ans,level+1);
        
    }

}
vector<int> rightview(node*root)
{
    vector<int > ans;
    solve(root,ans,0);
    return ans ;
}
int main() {
    // Creating a binary tree
    struct node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(6);
    root->right->right = new node(7);

    // Call the leftview function to get the left view of the tree
    vector<int> leftView = rightview(root);

    // Print the left view
    cout << "Left View of the binary tree is: ";
    for (int i = 0; i < leftView.size(); ++i) {
        cout << leftView[i] << " ";
    }

    return 0;
}