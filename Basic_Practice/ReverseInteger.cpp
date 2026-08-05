#include<iostream>
#include<cmath>
using namespace std;

int main() {

    int n;
    cout<<"Enter Number:";
    cin>>n;

    int rev = 0;

    while(n!=0) {
        int rem = n%10;
        rev = rev*10 + rem;
        n = n/10;
    }
    

    cout<<"Reverse of number"<<" is "<<rev<<endl;

    return 0;
}