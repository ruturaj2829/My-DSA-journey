#include <iostream>
#include <stack>
#include <queue>
#include <vector>
using namespace std;
struct node
{
    int data ;
   struct node*left;
   struct  node*right;
   
   node(int x){
        data = x;
        left=right=NULL;
   }
  
};
void traverseleft(node*root , vector<int>& ans){
    //base case
    if((root == NULL) || (root->left ==NULL && root->right == NULL)){
        return;
    }
    ans.push_back(root->data);
    if(root->left)
    traverseleft(root->left , ans);
    else{
       traverseleft(root->right , ans); 
    }
}
void leafselect(node*root , vector<int>& ans){
    if(root == NULL)  {
        return;
    }
   if (root->left ==NULL && root->right == NULL){
      ans.push_back(root->data);
   }

   leafselect(root->left,ans);
   leafselect(root->right,ans);
}
void traverseright(node*root , vector<int>& ans){
    //base case
    if((root == NULL) || (root->left ==NULL && root->right == NULL)){
        return;
    }
    ans.push_back(root->data);
    if(root->right)
    traverseleft(root->right, ans);
    else{
       traverseleft(root->left , ans); 
    }
}
vector<int> boundary(node* root){
    vector <int> ans ;
    if(root==NULL){
        return ans;
    }
    traverseleft(root,ans);
    leafselect(root,ans);
    traverseright(root,ans);
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
    root->right->left = new node(6);
    root->right->right = new node(7);
    root->left->left->left = new node(8);
    root->left->left->right = new node(9);

    // Find the boundary elements of the binary tree
    vector<int> boundaryResult = boundary(root);

    // Print the result
    cout << "Boundary Elements of the Binary Tree: ";
    for (int num : boundaryResult)
    {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
