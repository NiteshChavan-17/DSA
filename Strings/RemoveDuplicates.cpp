#include<iostream>
using namespace std;

string RemoveDuplicates(string s1) {

    int freq[26] = {0};
    string ans = "";

    for(int i=0;i<s1.length();i++) {
        if(freq[s1[i]-'a'] == 0) {
            ans+=s1[i];
            freq[s1[i]-'a'] = 1;
        }
    }

    return ans;
}

int main() {

    string s1;
    cout<<"Enter the string:";
    cin>>s1;

    string Duplicates = RemoveDuplicates(s1);

    cout<<"String after removing duplicate:"<<Duplicates<<endl;

    return 0;
}