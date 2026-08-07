#include <iostream>
using namespace std;

bool isPalindrome(string str) {

    int st = 0;
    int end = str.length() - 1;

    while(st < end) {

        if(str[st] != str[end]) {
            return false;
        }

        st++;
        end--;
    }

    return true;
}

int main() {

    string str;

    cout << "Enter String: ";
    cin >> str;

    if(isPalindrome(str))
        cout << "Palindrome";
    else
        cout << "Not Palindrome";

    return 0;
}