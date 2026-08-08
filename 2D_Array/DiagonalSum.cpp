#include <iostream>
using namespace std;

int DiagonalSum(int arr[][100], int n) {

    int sum = 0;

    for(int i = 0; i < n; i++) {

        for(int j = 0; j < n; j++) {

            if(i == j) {
                sum += arr[i][j];
            }
            else if(j == n - i - 1) {
                sum += arr[i][j];
            }
        }
    }

    return sum;
}

int main() {

    int n;

    cout << "Enter Size of Square Matrix: ";
    cin >> n;

    int arr[100][100];

    cout << "Enter Elements:\n";

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }

    cout << "Diagonal Sum = " << DiagonalSum(arr, n);

    return 0;
}