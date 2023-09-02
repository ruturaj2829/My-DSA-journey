#include<iostream>
#include<vector>
using namespace std;
const string  keypad [] = {
  "",
  "",
  "abc",
  "def",
  "ghi",
  "jkl",
  "mno",
  "pqrs",
  "tuv",
  "wxyz"
};
void genereatekeypadsatirng(string digits , int i , string current , vector<string>& results){

//base case
        if(i==digits.size()){
            results.push_back(current);
            return;        }
           // covert into digits;
            string letters = keypad[digits[i] - '0'];
            //mapping numper to digits 
            for(char letter : letters){
                 genereatekeypadsatirng(digits,i+1,current+letter,results);
            }
}
vector<string> getKeypadStrings(string digits){
    vector<string> results;
    if(digits.empty()){
        return results;

    }
    genereatekeypadsatirng(digits,0," ", results);

 return results;

}
int main() {
    string digits;  
    cin >> digits;

    vector<string> keypadStrings = getKeypadStrings(digits);

    cout << "Possible strings: " << endl;
    for (string str : keypadStrings) {
        cout << str << endl;
    }

    return 0;
}
/*The input is read as "23".

The getKeypadStrings function is called with the input "23".

Inside the getKeypadStrings function:

The generateKeypadStrings function is called with digits = "23", idx = 0, current = "", and an empty result vector.
Inside the generateKeypadStrings function (idx = 0, current = ""):

The letters corresponding to the digit '2' are "abc".
The loop iterates through each letter ('a', 'b', 'c') and makes recursive calls with updated parameters:
Call 1: generateKeypadStrings("23", 1, "a", result)
Call 2: generateKeypadStrings("23", 1, "b", result)
Call 3: generateKeypadStrings("23", 1, "c", result)
Inside each of the recursive calls (idx = 1, current = "a"/"b"/"c"):

The letters corresponding to the digit '3' are "def".
The loop iterates through each letter ('d', 'e', 'f') and makes recursive calls with updated parameters:
Call 1: generateKeypadStrings("23", 2, "ad", result)
Call 2: generateKeypadStrings("23", 2, "ae", result)
Call 3: generateKeypadStrings("23", 2, "af", result)
Call 4: generateKeypadStrings("23", 2, "bd", result)
Call 5: generateKeypadStrings("23", 2, "be", result)
Call 6: generateKeypadStrings("23", 2, "bf", result)
Call 7: generateKeypadStrings("23", 2, "cd", result)
Call 8: generateKeypadStrings("23", 2, "ce", result)
Call 9: generateKeypadStrings("23", 2, "cf", result)
The base case is reached for each of these recursive calls (idx == 2), and the current strings ("ad", "ae", ..., "cf") are added to the result vector.

Once all recursive calls are completed, the getKeypadStrings function returns the result vector.

The main function prints the possible strings:
*/



/*explanation for these lines*/ 
 /* for(char letter : letters){
                 genereatekeypadsatirng(digits,i+1,current+letter,results);
            }     */       

/*In these lines, you have a loop that iterates through each character letter in the letters string, which contains the letters corresponding to the current digit.

For each of these letters, you are making a recursive call to the generateKeypadStrings function with the following parameters:

digits remains the same, as it is the original input string.
i + 1 is used as the new index. This means you are moving to the next digit in the input string.
current + letter appends the current letter to the current string. This represents the string being built using the keypad mappings.
results is the vector that will eventually store all the generated keypad strings.
By doing this, you are effectively exploring all possible combinations of letters for the given digits in the input string. The recursion iterates over each digit, generating all possible strings by trying out different letters associated with each digit and then moving on to the next digit.

For example, if the input is "23", the loop will iterate over "abc" for digit '2', and for each letter, it will explore the letters "def" for digit '3', and so on. This leads to the generation of all possible strings.*/
             