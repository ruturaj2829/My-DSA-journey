#include <iostream>
#include <stack>
using namespace std;

stack<int> ans;

void reverseStack(stack<int>& s) {
    if (s.empty()) {
        return;
    }
    int num = s.top();
    s.pop();
    reverseStack(s); // Recursively reverse the remaining elements in s
    ans.push(num);   // Push the elements onto ans after the recursion
}

int main() {
    std::stack<int> myStack;

    // Push elements onto the stack
    myStack.push(1);
    myStack.push(2);
    myStack.push(3);
    myStack.push(6);
    myStack.push(5);

    std::cout << "Original Stack: ";
    stack<int> tempStack; // Create a temporary stack to store the reversed result
    while (!myStack.empty()) {
        tempStack.push(myStack.top());
        myStack.pop();
    }
    while (!tempStack.empty()) {
        std::cout << tempStack.top() << " ";
        myStack.push(tempStack.top()); // Restore the original stack
        tempStack.pop();
    }
    std::cout << std::endl;

    // Call the reverseStack function
    reverseStack(myStack);

    std::cout << "Reversed Stack: ";
    while (!ans.empty()) {
        std::cout << ans.top() << " ";
        ans.pop();
    }
    std::cout << std::endl;

    return 0;
}
