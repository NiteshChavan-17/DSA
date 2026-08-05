#include<iostream>
#include<climits>
using namespace std;

int BuyandSellStock(int arr[], int n) {

    int best_buy = arr[0];
    int maxProfit = 0;

    for(int i=1;i<n;i++) {
        if(arr[i]>best_buy){
            maxProfit = max(maxProfit, arr[i]-best_buy);
        }
        best_buy = min(best_buy,arr[i]);
    }

    return maxProfit;
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

    int Buy_Sell = BuyandSellStock(arr, n);

    cout<<"Max Profit:"<<Buy_Sell<<endl;

    return 0;
}