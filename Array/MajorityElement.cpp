#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int MajorityElement(vector<int>arr,int n) {

    int freq = 1;
    sort(arr.begin(),arr.end());

    int ans = arr[0];
    for(int i=1;i<n;i++) {
        if(arr[i-1] == arr[i]) {
            freq++;
        }
        else{
            freq = 1;
            ans = arr[i];
        }

        if(freq>=n/2) {
            return ans;
        }
    }
    
    return ans;
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

    int majority = MajorityElement(arr,n);

    cout<<"\nMajority Element:"<<majority<<endl;

    return 0;

}