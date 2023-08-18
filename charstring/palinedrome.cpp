#include <iostream>
using namespace std;

bool isPalindrome(string str)
{
int length = str.length();
for (int i = 0; i < length / 2;i++) {
    if (tolower(str[i]) != tolower(str[length - 1 - i])) {
         return false;
    } // if
  } // for loop
 return true;
}// isPalindrome  

int main() {
	
	// Example string.
	string s = "Madam";
	cout<<isPalindrome(s);
	cout<<endl;
	return 0;
}