#include <iostream>
using namespace std;
#include <stack>
#include <vector>

class NStack
{
    int *arr;
    int *top;
    int *next;
    int n, s;
    int freespot;

public:
    // Initialize your data structure
    NStack(int N, int S)
    {

        n = N;
        s = S;
        arr = new int[s];
        top = new int[n];
        next = new int[s];

        // Top initiate
        for (int i = 0; i < n; i++)
        {
            top[i] = -1;
        }
        // Next initiate
        for (int i = 0; i < s; i++)
        {
            next[i] = i + 1;
        }
        // Update last index to -1
        next[s - 1] = -1;

        // Initiate freespot
        freespot = 0;
    }
    bool push(int x, int m)
    {

        // Check for overflow
        if (freespot == -1)
            return false;

        // Find index
        int index = freespot;

        // Update freespot
        freespot = next[index];

        // Insert element into arr
        arr[index] = x;

        // Update next
        next[index] = top[m - 1];

        // Update top
        top[m - 1] = index;

        return true;
    }
    int pop(int m)
    {

        // Underflow check
        if (top[m - 1] == -1)
            return -1;

        int index = top[m - 1];

        top[m - 1] = next[index];

        next[index] = freespot;

        freespot = index;

        return arr[index];
    }
};

int main()
{
    int N = 3; // Number of stacks
    int S = 10; // Total size of the array

    NStack nStack(N, S);

    // Push elements into stack 1
    nStack.push(1, 1);
    nStack.push(2, 1);
    nStack.push(3, 1);

    // Push elements into stack 2
    nStack.push(4, 2);
    nStack.push(5, 2);

    // Push elements into stack 3
    nStack.push(6, 3);
    nStack.push(7, 3);
    nStack.push(8, 3);

    // Pop elements from stack 1
    cout << "Pop from stack 1: " << nStack.pop(1) << endl;
    cout << "Pop from stack 1: " << nStack.pop(1) << endl;

    // Pop elements from stack 2
    cout << "Pop from stack 2: " << nStack.pop(2) << endl;

    // Pop elements from stack 3
    cout << "Pop from stack 3: " << nStack.pop(3) << endl;
    cout << "Pop from stack 3: " << nStack.pop(3) << endl;

    return 0;
}
