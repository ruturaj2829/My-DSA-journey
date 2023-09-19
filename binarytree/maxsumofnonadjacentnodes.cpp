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
pair<int,int> solve(node*root){

    if(root==NULL){
        return {0,0};
    }
    pair<int,int> left = solve(root->left);
    pair<int,int> right= solve(root->right);

    pair<int,int> ans;

    ans.first = root->data + left.second + right.second;
    ans.second = max(left.first,left.second) + max(right.first,right.second);
    return ans;
    

}
 int maxadjacentsum(node* root){

    pair<int,int> ans = solve(root);
    return max(ans.first,ans.second);
    
    

}
int main(){

    node* root = new node(10);
    root->left = new node(1);
    root->right = new node(2);
    root->left->left = new node(3);
    root->right->left = new node(4);
    root->right->right = new node(5);

    cout<<maxadjacentsum(root)<<endl;
    return 0;
}