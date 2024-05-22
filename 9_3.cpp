//
// Created by Manas Singh on 22-05-2024.
//

#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int minimumCost(vector<int> &arr) {
    sort(arr.begin(), arr.end());
    int n = arr.size(), res = 0;
    for (int i = 1; i < n; i++) {
        arr[i] += arr[i - 1];
        res += arr[i];
    }
    return res;
}

int main() {
    int t;
    cout << "Enter the number of test cases: ";
    cin >> t;
    while (t-- > 0) {
        int n;
        cout << "Enter size of array: ";
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cout << "Enter size of file " << i << " : ";
            cin >> arr[i];
        }
        cout << "Minimum Computation Cost: " << minimumCost(arr) << endl;
        cout << endl;
    }
    return 0;
}