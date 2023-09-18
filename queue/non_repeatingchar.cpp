#include <iostream>
#include <stack>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

class Solution {
public:
    string firstNonRepeating(string a) {
        unordered_map<char, int> cnt;
        queue<char> q;
        string ans = " ";

        for (int i = 0; i < a.length(); i++) {
            char ch = a[i];
            cnt[ch]++;
            q.push(ch);

            while (!q.empty()) {
                if (cnt[q.front()] > 1) {
                    q.pop();
                } else {
                    ans.push_back(q.front());
                    break;
                }
            }
            if (q.empty())
                ans.push_back('#');
        }

        return ans;
    }
};

int main() {
    string input;
    cout << "Enter a string: ";
    cin >> input;

    Solution solution;
    string result = solution.firstNonRepeating(input);

    cout << "First non-repeating characters are: " << result << endl;

    return 0;
}
