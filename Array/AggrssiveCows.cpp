#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool isValid(vector<int>arr, int n, int c, int maxStall) {

    int cows = 1;
    int lastStallPos = arr[0];

    for(int i=1;i<n;i++) {
        if((arr[i]-lastStallPos) >= maxStall) {
            cows++;
            lastStallPos = arr[i];
        }

        if(cows==c) {
            return true;
        }
    }

    return false;
}

int AggrssiveCows(vector<int>arr, int n, int c) {

    sort(arr.begin(), arr.end());

    int s = 1;
    int e = arr[n-1] - arr[0];

    int ans = -1;

    while(s<=e) {
        int mid = s +(e-s)/2;

        if(isValid(arr, n, c, mid)) {
            ans = mid;
            s = mid + 1;
        }
        else{
            e = mid - 1;
        }
    }

    return ans;
}

int main() {

    vector<int>arr = {1, 4, 2, 8, 9};
    int n = 5, c = 3;

    cout<<"Minimum Possible max distance:"<<AggrssiveCows(arr,n,c)<<endl;

    return 0;
}