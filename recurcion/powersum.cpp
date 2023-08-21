#include<iostream>
#include<cmath>
using namespace std;
int powerSumHelper(int X, int N, int currentNum) {
    if (X == 0) {
        return 1; // Found a valid sum
    }
    if (X < 0 || currentNum <= 0) {
        return 0; // Invalid sum
    }
    
    // Include the current number raised to the power of N
    int includeCurrent = powerSumHelper(X - pow(currentNum, N), N, currentNum - 1);
    
    // Exclude the current number and move to the next one
    int excludeCurrent = powerSumHelper(X, N, currentNum - 1);
    
    return includeCurrent + excludeCurrent;
}

int powerSum(int X, int N) {
    return powerSumHelper(X, N, 1000);
}
int main() {
    int X, N;
    std::cout << "Enter X: ";
    std::cin >> X;
    std::cout << "Enter N: ";
    std::cin >> N;
    
    int ways = powerSum(X, N);
    std::cout << "Number of ways to express " << X << " as sum of two numbers raised to the power of " << N << " is: " << ways << std::endl;
    
    return 0;
}
