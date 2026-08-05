#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<pair<int,int>>Pair_sum(vector<int>arr, int target) {

    vector<pair<int,int>>ans;
    int n = arr.size();

    sort(arr.begin(),arr.end());

    int i = 0, j = n-1;

    while(i<=j) {
        int sum = arr[i] + arr[j];

        if(sum==target) {
            ans.push_back(make_pair(arr[i],arr[j]));
            i++;
            j--;
        }
        else if(sum>target) {
            j--;
        }
        else{
            i++;
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

    int target;
    cout<<"\nEnter the target:";
    cin>>target;

    vector<pair<int,int>>pairSum = Pair_sum(arr,target);

    for(int i=0;i<pairSum.size();i++) {
        cout<<" Pair:("<<pairSum[i].first<<","<<pairSum[i].second<<")";
    }
    
    return 0;
}