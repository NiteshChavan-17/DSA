#include<iostream>
#include<cmath>
using namespace std;

int main() {

    int n;
    cout<<"Enter the number:";
    cin>>n;

    bool isPrime = true;

    for(int i=2;i<n;i++) {
        if(n%i==0) {
            isPrime = false;
            cout<<"The number is not prime"<<endl;
            break;
        }
    }

    if(isPrime==true) {
        cout<<"Number is prime";
    }

    return 0;
}