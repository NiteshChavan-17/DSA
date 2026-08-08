#include <iostream>
#include <vector>
using namespace std;

bool searchMatrix(vector<vector<int>>& matrix, int target) {

    int m = matrix.size();
    int n = matrix[0].size();

    int r = 0;
    int c = n - 1;

    while(r < m && c >= 0) {

        if(target == matrix[r][c]) {
            return true;
        }
        else if(target < matrix[r][c]) {
            c--;
        }
        else {
            r++;
        }
    }

    return false;
}

int main() {

    int row, col;

    cout << "Enter number of rows and columns: ";
    cin >> row >> col;

    vector<vector<int>> matrix(row, vector<int>(col));

    cout << "Enter matrix elements:\n";

    for(int i = 0; i < row; i++) {
        for(int j = 0; j < col; j++) {
            cin >> matrix[i][j];
        }
    }

    int target;
    cout << "Enter target: ";
    cin >> target;

    if(searchMatrix(matrix, target))
        cout << "Element Found" << endl;
    else
        cout << "Element Not Found" << endl;

    return 0;
}