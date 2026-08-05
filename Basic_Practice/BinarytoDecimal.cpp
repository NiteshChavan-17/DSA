#include<iostream>
#include<cmath>
using namespace std;

int main() {

    int n;
    cout<<"Enter Number:";
    cin>>n;

    int i = 0;
    int ans = 0;

    while(n!=0) {
        int dig = n%10;
        ans = dig * pow(2,i) + ans;
        n = n/10;

        i++;
    }
    

    cout<<"Decimal of Binary number:"<<ans<<endl;

    return 0;
}