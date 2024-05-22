//
// Created by Manas Singh on 22-05-2024.
//

#include <vector>
#include <iostream>
#include <queue>

using namespace std;

void fractionalKnapsack(vector<pair<int, int>> &items, int size) {
    int n = items.size(), used;
    double res = 0;
    priority_queue<pair<double, pair<int, int>>> pq;
    vector<pair<int, int>> knapsack;
    for (int i = 0; i < n; i++)
        pq.push({(double) items[i].second / items[i].first, {i + 1, items[i].first}});
    while (size != 0) {
        auto temp = pq.top();
        pq.pop();
        used = min(size, temp.second.second);
        res += temp.first * used;
        size -= used;
        knapsack.push_back({temp.second.first, used});
    }
    cout << "Maximum value : " << res << endl;
    cout << "item-weight" << endl;
    for (auto &i: knapsack)
        cout << i.first << '-' << i.second << endl;
}

int main() {
    int t;
    cout << "Enter the number of test cases: ";
    cin >> t;
    while (t-- > 0) {
        int n, size;
        cout << "Enter number of items: ";
        cin >> n;
        vector<pair<int, int>> items(n);
        cout << "Enter weight of items: ";
        for (int i = 0; i < n; i++)
            cin >> items[i].first;
        cout << "Enter value of items: ";
        for (int i = 0; i < n; i++)
            cin >> items[i].second;
        cout << "Enter size of Knapsack: ";
        cin >> size;
        fractionalKnapsack(items, size);
        cout << endl;
    }
    return 0;
}