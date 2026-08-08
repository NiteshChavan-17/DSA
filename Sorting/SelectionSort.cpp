#include <iostream>
using namespace std;

void SelectionSort(int arr[], int n) {

    for(int i=0;i<n;i++) {
        int smallestIdx = i;

        for(int j=i+1;j<n;j++) {
            if(arr[j]<arr[smallestIdx]) {
                smallestIdx = j;
            }
        }

        swap(arr[i],arr[smallestIdx]);
    }
}

int main() {

    int arr[] = {5,3,1,4,2};
    int n = 5;

    SelectionSort(arr, n);

    cout << "Sorted Array: ";

    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}