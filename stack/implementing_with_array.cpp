#include<iostream>
using namespace std;
class Stack {
    int arr[10001];
    int i;
    int size;
public:
    
    Stack(int capacity) {
        // Write your code here.
        this->size = capacity;
        arr[size];
        i  = -1;
    }

    void push(int num) {
        // Write your code here.
        if(size-i>1){
            i++;
            arr[i] = num;
        }
        else{
            return;
        }
    }

    int pop() {
        // Write your code here.
        if(i>=0){
            int ans =  arr[i];
            i--;
            return ans;
        }
        return -1;
    }
    
    int top() {
        // Write your code here.
        if(i>=0){
            int ans =  arr[i];
            
            return ans;
        }
        return -1;

    }
    
    int isEmpty() {
        // Write your code here.
        if(i==-1){
            return 1;
        }
        return 0;
    }
    
    int isFull() {
        // Write your code here.
        if(i == size-1){
            return 1;
        }
        return 0;
    }
    
};
#include <iostream>

int main() {
    int capacity;
    std::cout << "Enter the capacity of the stack: ";
    std::cin >> capacity;

    Stack stack(capacity);

    int choice, num;
    do {
        std::cout << "Choose an operation:" << std::endl;
        std::cout << "1. Push" << std::endl;
        std::cout << "2. Pop" << std::endl;
        std::cout << "3. Top" << std::endl;
        std::cout << "4. Is Empty" << std::endl;
        std::cout << "5. Is Full" << std::endl;
        std::cout << "0. Exit" << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                std::cout << "Enter a number to push: ";
                std::cin >> num;
                stack.push(num);
                break;
            case 2:
                num = stack.pop();
                if (num != -1) {
                    std::cout << "Popped: " << num << std::endl;
                } else {
                    std::cout << "Stack is empty." << std::endl;
                }
                break;
            case 3:
                num = stack.top();
                if (num != -1) {
                    std::cout << "Top element: " << num << std::endl;
                } else {
                    std::cout << "Stack is empty." << std::endl;
                }
                break;
            case 4:
                if (stack.isEmpty()) {
                    std::cout << "Stack is empty." << std::endl;
                } else {
                    std::cout << "Stack is not empty." << std::endl;
                }
                break;
            case 5:
                if (stack.isFull()) {
                    std::cout << "Stack is full." << std::endl;
                } else {
                    std::cout << "Stack is not full." << std::endl;
                }
                break;
            case 0:
                std::cout << "Exiting program." << std::endl;
                break;
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
                break;
        }
    } while (choice != 0);

    return 0;
}


