#include<iostream>
using namespace std;

bool ArmStrong(int n) {

    int original = n;
    int sumofCubs = 0;

    while(n!=0) {
        int digit = n%10;
        sumofCubs+= digit*digit*digit;
        n = n/10;
    }

    if(sumofCubs == original) {
        return true;
    }

    return false;
}

int main() {
    int n;
    cout<<"Enter a number:";
    cin>>n;

    bool armstrong = ArmStrong(n);

    if(armstrong) {
        cout<<"Number is ArmStrong Number"<<endl;
    }

    else{
        cout<<"Number is not armstrong number"<<endl;
    }

    return 0;
}