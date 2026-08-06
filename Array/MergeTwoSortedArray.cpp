#include<iostream>
using namespace std;

void MergeSortedArray(int arr1[], int arr2[], int m, int n) {

    int i = m-1;
    int j = n-1;
    int idx = m+n-1;

    while(i>=0 && j>=0) {
        if(arr1[i]>=arr2[j]) {
            arr1[idx] = arr1[i];
            i--;
            idx--;
        }

        else{
            arr1[idx] = arr2[j];
            j--;
            idx--;
        }
    }

    while(j>=0) {
        arr1[idx] = arr2[j];
        j--;
        idx--;
    }
}

void print(int arr[], int n) {
    for(int i=0;i<n;i++) {
        cout<<arr[i]<<" ";
    }
}

int main() {

    int n;
    cout<<"Enter the size of Array 1:";
    cin>>n;

    int m;
    cout<<"Enter the size of Array 2:";
    cin>>m;

    int arr1[n];
    int arr2[m];
    cout<<"Enter the Elements of array 1:";
    for(int i=0;i<n;i++) {
        cin>>arr1[i];
    }

    cout<<"Enter the Elements of array 2:";
    for(int i=0;i<m;i++) {
        cin>>arr2[i];
    }

    cout<<"Array 1 Elements:"<<endl;
    print(arr1,n);

    cout<<"\nArray 2 Elements:"<<endl;
    print(arr2,m);

    MergeSortedArray(arr1, arr2, m, n);
    cout<<"\nMerged Array:"<<endl;
    print(arr1,n);
}