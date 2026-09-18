#include<iostream>
#include<vector>
using namespace std;

vector<int>countCharTypes(string s) {

    int uppercaseCount = 0;
    int LowerCaseCount = 0;
    int numbers = 0;

    vector<int>ans;

    for(int i=0;i<s.length();i++) {
        if(s[i]>='A' && s[i]<='Z') {
            uppercaseCount++;
        }

        else if(s[i]>='a' && s[i]<='z') {
            LowerCaseCount++;
        }

        else if(s[i]>='0' && s[i]<='9'){
            numbers++;
        }
    }
    ans.push_back(uppercaseCount);
    ans.push_back(LowerCaseCount);
    ans.push_back(numbers);

    return ans;
}

int main() {

    string s;
    cout<<"Enter the string:";
    cin>>s;

    vector<int>res = countCharTypes(s);

    cout<<res[0]<<" "<<res[1]<<" "<<res[2]<<endl;

    return 0;
}