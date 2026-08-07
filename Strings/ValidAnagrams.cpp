#include<iostream>
using namespace std;

bool ValidAnagram(string s1, string s2) {

    int freq[26] = {0};

    for(int i=0;i<s1.length();i++) {
        freq[s1[i]-'a']++;
    }

    for(int i=0;i<s2.length();i++) {
        freq[s2[i]-'a']--;
    }

    for(int i=0;i<26;i++) {
        if(freq[i]!=0) {
            return false;
        }
    }

    return true;
}

int main() {

    string s1;
    cout<<"Enter first string:";
    getline(cin,s1);

    string s2;
    cout<<"Enter second string:";
    getline(cin,s2);

    int Anagram = ValidAnagram(s1,s2);

    if(Anagram==true) {
        cout<<"Strings are anagram"<<endl;
    }
    else{
        cout<<"Strings are not anagram"<<endl;
    }

    return 0;
}