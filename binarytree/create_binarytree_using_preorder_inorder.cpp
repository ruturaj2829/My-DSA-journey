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

node* solve(int in[], int pre[], int n, map<int, int>& nodeindex, int instart, int inend, int& index) {
    if ((index >= n) || (instart > inend)) {
        return NULL;
    }
    int element = pre[index++];
    node* root = new node(element); // Fix here, use element instead of index
    int pos = nodeindex[element];
    root->left = solve(in, pre, n, nodeindex, instart, pos - 1, index);
    root->right = solve(in, pre, n, nodeindex, pos + 1, inend, index);
    return root;
}

node* buildtree(int in[], int pre[], int n) {
    int index = 0;
    map<int, int> nodeindex;
    return solve(in, pre, n, nodeindex, 0, n - 1, index); // Fix here, return the root
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