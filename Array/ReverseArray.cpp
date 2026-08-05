#include<iostream>
using namespace std;

void ReverseArray(int arr[], int n) {

    int i = 0;
    int j = n-1;
    
    while(i<j) {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
        i++;
        j--;
    }
}

void print(int arr[], int n) {

    for(int i=0;i<n;i++) {
        cout<<arr[i]<<" ";
    }
}

int main() {

    int n;
    cout<<"Enter the size of Array:";
    cin>>n;

    int arr[n];
    cout<<"Enter the Elements of array:";
    for(int i=0;i<n;i++) {
        cin>>arr[i];
    }

    cout<<"Array Elements:"<<endl;
    print(arr,n);

    ReverseArray(arr,n);

    cout<<"\nReversed Array:"<<endl;
    print(arr,n);

    return 0;
}