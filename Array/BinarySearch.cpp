#include<iostream>
using namespace std;

int Binary_Search(int arr[], int n, int target) {

    int s = 0;
    int e = n-1;
    while(s<=e) {
        int mid = s + (e-s)/2;

        if(mid==target) {
            return mid;
        }
        else if(target<mid) {
            e = mid - 1;
        }
        else{
            s = mid + 1;
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

    int BinarySearch = Binary_Search(arr, n, target);

    if(BinarySearch==-1) {
        cout<<"Target Element not found"<<endl;
    }
    else{
        cout<<"Target Element foumd"<<endl;
    }

    return 0;
}