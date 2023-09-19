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

    

}
int maxadjacentsum(node* root){

    pair<int,int> ans = solve(root);
    return max(ans.first,ans.second);
    

}