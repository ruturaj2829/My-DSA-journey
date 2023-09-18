#include <iostream>
#include <stack>
#include <vector>
#include <queue>
using namespace std;

void modifyqueue(queue<int> &q, int k) {
    stack<int> s;
    for (int i = 0; i < k; i++) {
        int val = q.front();
        q.pop();
        s.push(val);
    }

    while (!s.empty()) {
        int val = s.top();
        s.pop();
        q.push(val);
    }

    int t = q.size() - k;
    while (t--) {
        int val = q.front();
        q.pop();
        q.push(val);
    }
}

int main() {
    queue<int> q;
    
    // Populate the queue with some initial elements
    for (int i = 1; i <= 5; i++) {
        q.push(i);
    }
    
    int k = 3; // Number of elements to move to the end
    
    cout << "Original Queue: ";
    queue<int> originalQueue = q;  // Make a copy of the original queue for printing
    while (!originalQueue.empty()) {
        cout << originalQueue.front() << " ";
        originalQueue.pop();
    }
    cout << endl;

    modifyqueue(q, k);

    cout << "Modified Queue: ";
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;

    return 0;
}


