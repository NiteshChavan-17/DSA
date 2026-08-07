#include<iostream>
#include<vector>
using namespace std;

bool isValid(vector<int>arr, int n, int k, int maxTime) {

    int painter = 1;
    int time = 0;

    for(int i=0;i<n;i++) {
        if(arr[i]>maxTime) {
            return false;
        }

        if(time + arr[i] <= maxTime) {
            time+=arr[i];
        }
        else{
            painter++;
            time = arr[i];

            if(painter>k) {
                return false;
            }
        }
    }

    return true;
}

int PaintBoard(vector<int>arr, int n, int k) {

    int sum = 0;
    int minval = INT_MIN;
    int ans = -1;
    for(int i=0;i<n;i++) {
        sum+=arr[i];
        minval = max(minval, arr[i]);
    }

    int s = minval;
    int e = sum;

    while(s<=e) {
        int mid = s + (e-s)/2;

        if(isValid(arr,n,k,mid)) {
            ans = mid;
            e = mid - 1;
        }
        else{
            s = mid + 1;
        }
    }

    return ans;
}

int main() {
    vector<int>arr = {10,20,30,40};
    int n = 4 , k = 2;

    cout<<"Minimum Possible time:"<<PaintBoard(arr,n,k)<<endl;
}