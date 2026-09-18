#include<iostream>
using namespace std;

bool PalindromeString(string s) {

    int i=0;
    int j = s.length() - 1;

    while(i<j) {
        if(s[i]!=s[j]) {
            return false;
        }

        i++;
        j--;
    }

    return true;
}

int main() {

    string s;
    cout<<"Enter the string:";
    cin>>s;

    bool palindrome = PalindromeString(s);

    if(palindrome) {
        cout<<"String is palindrome"<<endl;
    }

    else{
        cout<<"String is not Palindrome"<<endl;
    }

    return 0;
}