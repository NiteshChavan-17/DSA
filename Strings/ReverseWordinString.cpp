#include <iostream>
#include <algorithm>
using namespace std;

string ReverseWords(string s) {

    // Step 1: Reverse the entire string
    reverse(s.begin(), s.end());

    string ans = "";
    int n = s.length();
    int i = 0;

    while(i < n) {

        string word = "";

        // Skip extra spaces
        while(i < n && s[i] == ' ')
            i++;

        // Store one word
        while(i < n && s[i] != ' ') {
            word += s[i];
            i++;
        }

        // Reverse the word
        reverse(word.begin(), word.end());

        // Append to answer
        if(word.length() > 0) {
            ans+= " " + word;
        }
    }

    return ans.substr(1);
}

int main() {

    string s;

    cout << "Enter String: ";
    getline(cin, s);

    cout << "Reversed Words: " << ReverseWords(s);

    return 0;
}