#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <map>
using namespace std;

struct node {
    int data;
    struct node* left;
    struct node* right;

    node(int x) {
        data = x;
        left = right = NULL;
    }
};

void createnodeindex(int in[], map<int, int>& nodeindex, int n) {
    for (int i = 0; i < n; i++) {
        nodeindex[in[i]] = i;
    }
}

node* solve(int in[], int post[], int n, map<int, int>& nodeindex, int instart, int inend, int& index) {
    if ((index < 0) || (instart > inend)) {
        return NULL;
    }
    int element = post[index++];
    node* root = new node(element); // Fix here, use element instead of index
    int pos = nodeindex[element];
    root->right = solve(in, post, n, nodeindex, pos + 1, inend, index);
    root->left = solve(in, post, n, nodeindex, instart, pos - 1, index);
    
    return root;
}

node* buildtree(int in[], int post[], int n) {
    int index = n-1;
    map<int, int> nodeindex;
    return solve(in, post , n, nodeindex, 0, n - 1, index); // Fix here, return the root
}

int main() {
    int n;
    cin >> n;
    int* in = new int[n]; // Dynamically allocate memory for in[]
    int* pre = new int[n]; // Dynamically allocate memory for pre[]
    
    for (int i = 0; i < n; i++) {
        cin >> in[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> pre[i];
    }
    
    node* root = buildtree(in, pre, n);

    // Don't forget to free the dynamically allocated memory
    delete[] in;
    delete[] pre;

    return 0;
}