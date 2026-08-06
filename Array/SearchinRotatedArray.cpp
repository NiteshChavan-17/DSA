#include<iostream>
using namespace std;

int SearchinRotated(int arr[], int n, int target) {

    int s = 0; int e = n-1;

    while(s<=e) {
        int mid = s+(e-s)/2;

        if(arr[mid]==target) {
            return mid;
        }

        if(arr[s]<=arr[mid]) {
            if(arr[s]<=target && target<=arr[mid]) {
                e = mid - 1;
            }
            else{
                s = mid + 1;
            }
        }
        else{
            if(arr[mid]<=target && target<=arr[e]) {
                s = mid + 1;
            }
            else{
                e = mid - 1;
            }
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

    int SerachinRotated = SearchinRotated(arr,n,target);

    if(SerachinRotated==-1) {
        cout<<"Target not found"<<endl;
    }
    else{
        cout<<"Target found"<<endl;
    }

    return 0;
}