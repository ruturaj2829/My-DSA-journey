#include <iostream>
using namespace std;
#include <stack>

// ignoring the stack space used while recursion, Space Complexity: O(1)

void sortInsert(stack<int> &stack,int top){

    if(stack.empty()){

        stack.push(top); 

    }

    else if(stack.top()<top){

        stack.push(top);

    }else{ // if we haven't reached the desired position where element should be present

        int temp=stack.top();

        stack.pop();

        sortInsert(stack,top);

        stack.push(temp);

    }

    return;

}

void sortStack(stack<int> &stack)

{

    // Write your code here

    if(stack.empty()) return;

    int top=stack.top(); // to keep record of element we are removing

    stack.pop(); // remove the element from stack

    sortStack(stack); // calling function untill whole stack gets empty

    sortInsert(stack,top); // passing current removed element and stack 

    return;

}
int main() {
    stack<int> s;
    s.push(5);
    s.push(2);
    s.push(9);
    s.push(1);
    s.push(6);

    cout << "Original Stack: ";
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;

    s.push(5);
    s.push(2);
    s.push(9);
    s.push(1);
    s.push(6);

    sortStack(s);

    cout << "Sorted Stack: ";
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;

    return 0;
}