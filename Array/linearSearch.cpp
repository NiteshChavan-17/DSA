#include<iostream>
using namespace std;

int Linear_Search(int arr[],int n,int target) {

    for(int i=0;i<n;i++) {
        if(arr[i]==target) {
            return i;
        }
    }

    return -1;
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

    int target;
    cout<<"\nEnter the target element to find:";
    cin>>target;

    int linearSearch = Linear_Search(arr, n, target);

    if(linearSearch==-1) {
        cout<<"Target Element not found"<<endl;
    }
    else{
        cout<<"Target Element foumd"<<endl;
    }

    return 0;
}