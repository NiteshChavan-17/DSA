#include<iostream>
using namespace std;

void swapAlternate(int arr[], int n) {

    int first = 0;
    for(int second=1;second<n;second+=2) {
        int temp = arr[first];
        arr[first] = arr[second];
        arr[second] = temp;
        first+=2;
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

    swapAlternate(arr,n);
    cout<<"\nArray after swapping alternate:"<<endl;
    print(arr,n);

    return 0;
}