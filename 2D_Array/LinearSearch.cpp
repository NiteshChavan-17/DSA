#include <iostream>
using namespace std;

bool LinearSearch(int arr[][100], int row, int col, int target) {

    for(int i = 0; i < row; i++) {

        for(int j = 0; j < col; j++) {

            if(arr[i][j] == target) {
                return true;
            }
        }
    }

    return false;
}

int main() {

    int row, col;

    cout << "Enter Rows and Columns: ";
    cin >> row >> col;

    int arr[100][100];

    cout << "Enter Elements:\n";

    for(int i = 0; i < row; i++) {
        for(int j = 0; j < col; j++) {
            cin >> arr[i][j];
        }
    }

    int target;

    cout << "Enter Target: ";
    cin >> target;

    if(LinearSearch(arr, row, col, target))
        cout << "Element Found";
    else
        cout << "Element Not Found";

    return 0;
}