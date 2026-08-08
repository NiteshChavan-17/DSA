#include <iostream>
using namespace std;

void RowSum(int arr[][100], int row, int col) {

    for(int i = 0; i < row; i++) {

        int sum = 0;

        for(int j = 0; j < col; j++) {
            sum += arr[i][j];
        }

        cout << "Row " << i + 1 << " Sum = " << sum << endl;
    }
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

    RowSum(arr, row, col);

    return 0;
}