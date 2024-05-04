#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<pair<int, int>> giants(N);
    for (int i = 0; i < N; ++i) {
        cin >> giants[i].first >> giants[i].second;
    }

    sort(giants.begin(), giants.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
        return (a.second - a.first) < (b.second - b.first);
    });

    long long current_height = 0;
    long long max_head_height = 0;
    for (auto& giant : giants) {
        int A = giant.first;
        int B = giant.second;
        current_height += A;
        max_head_height = max(max_head_height, current_height + (B - A));
    }

    cout << max_head_height << endl;
    return 0;
}
