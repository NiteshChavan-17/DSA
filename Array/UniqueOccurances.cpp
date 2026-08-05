#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool UniqueOccurances(vector<int>arr) {

    vector<int>ans;
    int n = arr.size();
    sort(arr.begin(),arr.end());

    for(int i=0;i<n;i++) {
        int count = 1;
        while(i+1<n && arr[i]==arr[i+1]) {
            count++;
            i++;
        }

        ans.push_back(count);
    }

    sort(ans.begin(),ans.end());
    for(int i=1;i<ans.size();i++) {
        if(ans[i]==ans[i-1]) {
            return false;
        }
    }

    return true;

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

    bool uniqueOccurance = UniqueOccurances(arr);
    if(uniqueOccurance) {
        cout<<"Array contains unique occurance of element"<<endl;
    }
    else{
        cout<<"Array does not contains unique occurance of element"<<endl;
    }


    return 0;
}