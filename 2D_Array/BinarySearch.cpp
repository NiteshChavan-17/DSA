#include <iostream>
#include <vector>
using namespace std;

// Your functions here...

bool SearchinRow(vector<vector<int>>& matrix, int target, int Row) {

    int n = matrix[0].size();

    int st = 0;
    int end = n - 1;

    while(st <= end) {

        int mid = st + (end - st) / 2;

        if(target == matrix[Row][mid]) {
            return true;
        }
        else if(target > matrix[Row][mid]) {
            st = mid + 1;
        }
        else {
            end = mid - 1;
        }
    }

    return false;
}

bool searchMatrix(vector<vector<int>>& matrix, int target) {

    int m = matrix.size();
    int n = matrix[0].size();

    int startRow = 0;
    int endRow = m - 1;

    while(startRow <= endRow) {

        int midRow = startRow + (endRow - startRow) / 2;

        if(target >= matrix[midRow][0] && target <= matrix[midRow][n - 1]) {

            return SearchinRow(matrix, target, midRow);
        }
        else if(target > matrix[midRow][n - 1]) {
            startRow = midRow + 1;
        }
        else {
            endRow = midRow - 1;
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
        cout << "Target Found" << endl;
    else
        cout << "Target Not Found" << endl;

    return 0;
}