#include<iostream>
#include<vector>
using namespace std;

bool isValid(vector<int>arr, int n,int m, int maxAllowed) {

    int st = 1;
    int pages = 0;

    for(int i=0;i<n;i++) {
        if(arr[i]>maxAllowed) {
            return false;
        }

        if(pages+arr[i]<=maxAllowed) {
            pages+=arr[i];
        }
        else{
            st++;
            pages = arr[i];
        }
    }

    return st > m ? false : true;
}

int AllocateBooks(vector<int>arr, int n, int m) {

    if(m>n) {
        return -1;
    }
    int s = 0;
    int sum = 0;

    int ans = -1;
    for(int i=0;i<n;i++) {
        sum+=arr[i];
    }

    int e = sum;
    while(s<=e) {
        int mid = s + (e-s)/2;

        if(isValid(arr,n,m,mid)) {
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

    vector<int>arr = {2,1,3,4};

    int n = 4, m = 2;
    cout<<"Minimum No. of Pages:"<<AllocateBooks(arr,n,m)<<endl;
}