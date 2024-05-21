//
// Created by Manas Singh on 17-05-2024.
//
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

int kruskal(int n, vector<vector<int>> &matrix) {
    vector<int> parent(n), rank(n, 1);
    int res = 0;
    for (int i = 0; i < n; i++)
        parent[i] = i;
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (matrix[i][j])
                pq.emplace(matrix[i][j], make_pair(i, j));

}

int main() {
    int t;
    cout << "Enter the number of test cases: ";
    cin >> t;
    while (t-- > 0) {
        int n;
        cout << "Enter number of nodes: ";
        cin >> n;
        vector<vector<int>> matrix(n, vector<int>(n));
        cout << "Enter adjacency matrix: " << endl;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                cin >> matrix[i][j];
        cout << "Minimum Spanning Weight: " << kruskal(n, matrix) << endl;
        cout << endl;
    }
    return 0;
}