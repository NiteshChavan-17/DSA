#include<iostream>
using namespace std;

int FrequencyNum(int n, int arr[], int X) {

    int count = 0;

    for(int i=0;i<n;i++) {
        if(arr[i]==X) {
            count++;
        }
    }

    return count;
}

int main() {
    int n;
    cout<<"Enter the size of array:";
    cin>>n;

    int arr[n];
    cout<<"Enter the array elements:";
    for(int i=0;i<n;i++) {
        cin>>arr[i];
    }

    int X;
    cout<<"Enter the number whose frequecy to be calculated:";
    cin>>X;

    int frequencyCount = FrequencyNum(n,arr,X);

    cout<<"Frequency of "<<X<<" in array:"<<frequencyCount<<endl;

    return 0;
}