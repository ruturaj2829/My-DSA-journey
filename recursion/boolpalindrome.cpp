#include <iostream>
using namespace std;

bool checkpalindrome(string str, int i, int j) {
    if (i >= j) {
        return true;
    }
    
    if (str[i] != str[j]) {
        return false;
    } else {
        return checkpalindrome(str, ++i, --j);
    }
}

int main() {
    string str = "abbca";
    bool ispalindrome = checkpalindrome(str, 0, str.length() - 1);
    
    if (ispalindrome) {
        cout << "It is a palindrome" << endl;
    } else {
        cout << "It is not a palindrome" << endl;
    }

    return 0;
}
