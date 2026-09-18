#include<iostream>
#include<cmath>
using namespace std;

int main() {

    int n;
    cout<<"Enter the number:";
    cin>>n;

    int original = n;
    int reverse = 0;
    int i = 0;
    while(n!=0) {
        int rem = n%10;
        reverse = reverse*10 + rem;
        n = n/10;
        i++;
    }

    if(reverse==original) {
        cout<<"Number is Palindrome"<<endl;
    }
    else{
        cout<<"Number is not palindrome"<<endl;
    }

    return 0;
}