#include<iostream>
using namespace std;

void DNF(int arr[], int n) {

    int low = 0, mid = 0, high = n-1;

    while(mid<=high) {
        if(arr[mid] == 0) {
            swap(arr[mid],arr[low]);
            low++, mid++;
        }
        else if(arr[mid]==1) {
            mid++;
        }
        else{
            swap(arr[mid],arr[high]);
            high--;
        }
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

    DNF(arr,n);
    cout<<"Sorted Array:"<<endl;
    print(arr,n);

    return 0;
}