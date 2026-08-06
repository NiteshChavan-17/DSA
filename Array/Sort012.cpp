#include<iostream>
using namespace std;

void Sort012(int arr[], int n) {

    int count0 = 0;
    int count1 = 0;
    int count2 = 0;

    for(int i=0;i<n;i++) {
        if(arr[i]==0) count0++;
        else if(arr[i]==1) count1++;
        else count2++;
    }

    int idx = 0;
    for(int i=0;i<count0;i++) {
        arr[idx++] = 0;
    }

    for(int i=0;i<count1;i++) {
        arr[idx++] = 1;
    }

    for(int i=0;i<count2;i++) {
        arr[idx++] = 2;
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

    Sort012(arr,n);
    cout<<"\nSorted Array:"<<endl;
    print(arr,n);

    return 0;
}