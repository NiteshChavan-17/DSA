#include<iostream>
#include<vector>
using namespace std;

vector<int>productofArray(vector<int>arr) {

    int suffix = 1;
    int n = arr.size();
    vector<int>ans(n,1);

    for(int i=1;i<n;i++) {
        ans[i] = ans[i-1] * arr[i-1];
    }

    for(int i=n-2;i>=0;i--) {
        suffix*= arr[i+1];
        ans[i]*=suffix;
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
    cout<<"Enter the size of Array:";
    cin>>n;

    vector<int>arr(n);
    cout<<"Enter the Elements of array:";
    for(int i=0;i<n;i++) {
        cin>>arr[i];
    }

    cout<<"Array Elements:"<<endl;
    print(arr,n);

    vector<int>Product = productofArray(arr);

    cout<<"\nElements after product:"<<endl;
    for(int i=0;i<Product.size();i++){
        cout<<Product[i]<<" ";
    }

    return 0;
}