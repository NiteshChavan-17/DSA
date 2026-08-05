#include<iostream>
using namespace std;

int unique(int arr[], int n) {

    int ans = 0;
    for(int i=0;i<n;i++) {
        ans = ans^arr[i];
    }

    return ans;
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

    int uniqueElement = unique(arr,n);
    cout<<"\nUnique Element in Array:"<<uniqueElement;

    return 0;
}