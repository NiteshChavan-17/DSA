#include<iostream>
#include<climits>
using namespace std;

int ContainerWithmaxWater(int height[], int n) {

    int i = 0;
    int j = n-1;
    int maxWater = 0;

    while(i<j) {
        int w = j-i;
        int h = min(height[i],height[j]);

        int area = w*h;

        maxWater = max(maxWater,area);

        height[i]<height[j] ? i++ :j--;
    }
    return maxWater;

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

    int Max_Water = ContainerWithmaxWater(arr, n);

    cout<<"\nMax Water:"<<Max_Water<<endl;

    return 0;
}