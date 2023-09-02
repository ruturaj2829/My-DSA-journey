// CPP program to generate power set
#include <iostream>
using namespace std;

// str : Stores input string
// curr : Stores current subset
// index : Index in current subset, curr
void powerSet(string str, int index = -1, string curr = "")
{
	int n = str.length();

	// base case
	if (index == n)
		return;

	// First print current subset
	cout << curr << "\n";

	// Try appending remaining characters
	// to current subset
	for (int i = index + 1; i < n; i++) {

		curr += str[i];
		powerSet(str, i, curr);

		// Once all subsets beginning with
		// initial "curr" are printed, remove
		// last character to consider a different
		// prefix of subsets.
		curr.erase(curr.size() - 1);
	}
	return;
}

// Driver code
int main()
{
	string str = "suzainshadab";
	powerSet(str);
	return 0;
}




