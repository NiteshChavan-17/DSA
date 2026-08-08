#include <iostream>
using namespace std;

void BubbleSort(int arr[], int n) {

    for(int i = 0; i < n - 1; i++) {

        bool swapped = false;

        for(int j = 0; j < n - i - 1; j++) {

            if(arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }

        if(!swapped)
            break;
    }
}

int main() {

    int arr[] = {5,3,1,4,2};
    int n = 5;

    BubbleSort(arr, n);

    cout << "Sorted Array: ";

    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}