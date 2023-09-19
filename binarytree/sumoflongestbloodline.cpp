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
void solve(node* root , int len , int &maxlen , int sum ,int &maxsum){
    if(root==NULL){
        
        if(len>maxlen){
            maxlen = len;
            maxsum=sum;
        }
        else{
            if(len==maxlen ){
                maxsum =max(sum,maxsum);
            }
          
        }
        return;
    }
    sum = sum + root->data;
    solve(root->left,len+1,maxlen,sum,maxsum);
    solve(root->right,len+1,maxlen,sum,maxsum);

}
int sumoflongestpath(node*root){
    int len = 0;
    int maxlen = 0;
    int sum = 0;
    int maxsum = INT_MIN;
    solve(root,len,maxlen,sum,maxsum);

    return maxsum;
}
int main(){
    // Creating a binary tree
    struct node* root = new node(4);
    root->left = new node(2);
    root->right = new node(5);
    root->left->left = new node(7);
    root->left->right = new node(1);
    root->right->left = new node(2);
    root->right->right = new node(3);
    root->left->right->left = new node(6);

    // Call the sumoflongestpath function to get the sum of the longest path
    int sum = sumoflongestpath(root);

    // Print the sum of the longest path
    cout << "Sum of the longest path is: " << sum << endl;

    return 0;
}