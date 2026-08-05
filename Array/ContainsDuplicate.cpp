#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool ContainsDuplicate(vector<int>arr) {

    int n = arr.size();
    sort(arr.begin(),arr.end());

    for(int i=1;i<n;i++) {
        if(arr[i]==arr[i-1]) {
            return true;
        }
    }
    return false;
}

void print(vector<int>arr, int n) {

    for(int i=0;i<n;i++) {
        cout<<arr[i]<<" ";
    }
}

int main() {

    int n;
    cout<<"Enter the size of vector:";
    cin>>n;

    vector<int>arr(n);
    cout<<"Enter the Elements of array:";
    for(int i=0;i<n;i++) {
        cin>>arr[i];
    }

    cout<<"Array Elements:"<<endl;
    print(arr,n);

    bool Duplicate = ContainsDuplicate(arr);
    if(Duplicate) {
        cout<<"\nArray contains Duplicate element"<<endl;
    }
    else{
        cout<<"\nArray does not contains Duplicate element"<<endl;
    }


    return 0;
}