#include<iostream>
using namespace std;

int main() {

    int n;
    cout<<"Enter the size of array:";
    cin>>n;

    int arr[n];
    cout<<"Enter the elements of array:";
    for(int i=0;i<n;i++) {
        cin>>arr[i];
    }

    int largest = INT_MIN;
    int sec_largest = INT_MIN;

    for(int i=0;i<n;i++) {
        if(arr[i]>largest) {
            sec_largest = largest;
            largest = arr[i];
        }

        if(arr[i]>sec_largest && arr[i]<largest) {
            sec_largest = arr[i];
        }
    }

    cout<<"Second Largest Element:"<<sec_largest<<endl;

    return 0;
}