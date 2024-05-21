//
// Created by Manas Singh on 21-05-2024.
//
#include <vector>
#include <iostream>

using namespace std;

void floydWarshall(int n, vector<vector<int>> &matrix) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            for (int k = 0; k < n; k++)
                if (matrix[j][k])
                    for (int l = 0; l < n; l++) {
                        if (matrix[j][l] && matrix[l][k] && matrix[j][l] != -1 && matrix[l][k] != -1 &&
                            (matrix[j][k] == -1 || matrix[j][k] > matrix[j][l] + matrix[l][k]))
                            matrix[j][k] = matrix[j][l] + matrix[l][k];
                    }
}

int main() {
    int t;
    cout << "Enter the number of test cases: ";
    cin >> t;
    while (t-- > 0) {
        int n, source;
        cout << "Enter number of nodes: ";
        cin >> n;
        vector<vector<int>> matrix(n, vector<int>(n));
        cout << "Enter adjacency matrix: " << endl;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                cin >> matrix[i][j];
        floydWarshall(n, matrix);
        cout << "Shortest Distance Matrix:" << endl;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++)
                cout << matrix[i][j] << " ";
            cout << endl;
        }
        cout << endl;
    }
    return 0;
}