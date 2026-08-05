#include<iostream>
#include<climits>
using namespace std;

int maxSubArraySum(int arr[], int n) {

    int currSum = 0;
    int maxSum = INT_MIN;

    for(int i=0;i<n;i++) {
        currSum+=arr[i];

        maxSum = max(currSum,maxSum);
        if(currSum<0) {
            currSum = 0;
        }
    }

    return maxSum;
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

    int maxArray = maxSubArraySum(arr, n);

    cout<<"Max Subarray Sum:"<<maxArray<<endl;

    return 0;
}