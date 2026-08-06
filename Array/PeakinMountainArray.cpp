#include<iostream>
using namespace std;

int PeakinMountain(int arr[], int n) {
    int s = 0;
    int e = n-1;

    while(s<=e) {
        int mid = s + (e-s)/2;

        if(arr[mid]>arr[mid-1] && arr[mid]>arr[mid+1]) {
            return arr[mid];
        }
        else if(arr[mid]<arr[mid+1]) {
            s = mid + 1;
        }
        else{
            e = mid - 1;
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


    int peakinMountain = PeakinMountain(arr,n);

    cout<<"\nPeak Element in array is at index:"<<peakinMountain<<endl;

    return 0;
}