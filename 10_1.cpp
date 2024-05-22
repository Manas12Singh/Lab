//
// Created by Manas Singh on 22-05-2024.
//

#include <vector>
#include <queue>
#include <iostream>

using namespace std;

void activitySelection(vector<pair<int, int>> &activity) {
    int n = activity.size(), lastEnd = 0, count = 0;
    vector<int> res;
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;
    for (int i = 0; i < n; i++)
        pq.push({activity[i].second, {i + 1, activity[i].first}});
    while (!pq.empty()) {
        auto temp = pq.top();
        pq.pop();
        if (temp.second.second >= lastEnd) {
            count++;
            lastEnd = temp.first;
            res.push_back(temp.second.first);
        }
    }
    cout << "No. of non-conflicting activities: " << count << endl;
    cout << "List of selected activities: ";
    for (int &i: res)
        cout << i << ", ";
    cout << endl;
}

int main() {
    int t;
    cout << "Enter the number of test cases: ";
    cin >> t;
    while (t-- > 0) {
        int n;
        cout << "Enter number of activities: ";
        cin >> n;
        vector<pair<int, int>> activity(n);
        cout << "Enter starting time: ";
        for (int i = 0; i < n; i++)
            cin >> activity[i].first;
        cout << "Enter ending time: ";
        for (int i = 0; i < n; i++)
            cin >> activity[i].second;
        activitySelection(activity);
        cout << endl;
    }
    return 0;
}