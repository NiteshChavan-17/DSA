#include<iostream>
using namespace std;

int main() {

    char c;
    cout<<"Enter the character:";
    cin>>c;

    if(c>='a' && c<='z') {
        c = c-('a' - 'A');
        cout<<c<<endl;
    }

    if(c>='A' && c<='Z') {
        c = c+('a'-'A');
        cout<<c<<endl;
    }

    return 0;
}