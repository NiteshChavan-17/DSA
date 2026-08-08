#include <iostream>
#include <vector>
using namespace std;

vector<int> spiralOrder(vector<vector<int>>& mat) {

    vector<int> ans;

    int m = mat.size();
    int n = mat[0].size();

    int srow = 0, erow = m - 1;
    int scol = 0, ecol = n - 1;

    while(srow <= erow && scol <= ecol) {

        // Top
        for(int i = scol; i <= ecol; i++) {
            ans.push_back(mat[srow][i]);
        }

        // Right
        for(int i = srow + 1; i <= erow; i++) {
            ans.push_back(mat[i][ecol]);
        }

        // Bottom
        for(int i = ecol - 1; i >= scol; i--) {
            if(srow == erow)
                break;

            ans.push_back(mat[erow][i]);
        }

        // Left
        for(int i = erow - 1; i >= srow + 1; i--) {
            if(scol == ecol)
                break;

            ans.push_back(mat[i][scol]);
        }

        srow++;
        erow--;
        scol++;
        ecol--;
    }

    return ans;
}

int main() {

    int row, col;

    cout << "Enter rows and columns: ";
    cin >> row >> col;

    vector<vector<int>> mat(row, vector<int>(col));

    cout << "Enter matrix elements:\n";

    for(int i = 0; i < row; i++) {
        for(int j = 0; j < col; j++) {
            cin >> mat[i][j];
        }
    }

    vector<int> ans = spiralOrder(mat);

    cout << "Spiral Order: ";

    for(int x : ans) {
        cout << x << " ";
    }

    return 0;
}