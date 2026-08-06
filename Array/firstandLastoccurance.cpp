#include<iostream>
using namespace std;

int FirstOccurance(int arr[],int n, int target) {
    
    int s = 0;
    int e = n-1;
    int ans = 0;

    while(s<=e) {
        int mid = s + (e-s)/2;

        if(arr[mid] == target) {
            ans = mid;
            e = mid - 1;
        }
        else if(arr[mid]<target) {
            s = mid + 1;
        }
        else{
            e = mid - 1;
        }
    }

    return ans;
}

int LastOccurance(int arr[],int n, int target) {
    
    int s = 0;
    int e = n-1;
    int ans = 0;

    while(s<=e) {
        int mid = s + (e-s)/2;

        if(arr[mid] == target) {
            ans = mid;
            s = mid + 1;
        }
        else if(arr[mid]<target) {
            s = mid + 1;
        }
        else{
            e = mid - 1;
        }
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

    int target;
    cout<<"\nEnter the target Element:";
    cin>>target;


    int firstOccurance = FirstOccurance(arr,n, target);
    int lastOccurance = LastOccurance(arr,n,target);

    cout<<"\nFirst Occurance of Element in array is at index:"<<firstOccurance<<endl;
    cout<<"\nLast Occurance of Element in array is at index:"<<lastOccurance<<endl;

    return 0;
}