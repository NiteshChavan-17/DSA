#include<iostream>
using namespace std;

void NextPermutation(int arr[],int n) {

    int piv = -1;

    ///find pivot
    for(int i=n-2;i>=0;i--) {
        if(arr[i]<arr[i+1]) {
            piv = i;
            break;
        }
    }

    if(piv==-1) {
        int i = 0;
        int j = n-1;
        while(i<j) {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
        return;
    }

    //find rightmost element
    for(int i=n-1;i>piv;i--) {
        if(arr[i]>arr[piv]) {
            swap(arr[i],arr[piv]);
            break;
        }
    }

    int i = piv+1;
    int j = n-1;
    while(i<=j) {
        swap(arr[i], arr[j]);
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

    NextPermutation(arr, n);
    cout<<"\nNext Permutation of the array:";
    print(arr, n);
}