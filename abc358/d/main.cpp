#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    vector<pair<int, int>> boxes(N);
    for (int i = 0; i < N; i++) {
        cin >> boxes[i].second;
        boxes[i].first = i;
    }

    vector<int> B(M);
    for (int i = 0; i < M; i++) {
        cin >> B[i];
    }

    sort(boxes.begin(), boxes.end(), [](const auto& a, const auto& b) {
        return a.second < b.second;
    });

    sort(B.rbegin(), B.rend());

    vector<bool> used(N, false);
    int total_cost = 0;

    for (int i = 0; i < M; i++) {
        bool found = false;
        for (int j = 0; j < N; j++) {
            if (!used[j] && boxes[j].second >= B[i]) {
                used[j] = true;
                total_cost += boxes[j].second;
                found = true;
                break;
            }
        }
        if (!found) {
            cout << -1 << endl;
            return 0;
        }
    }

    cout << total_cost << endl;

    return 0;
}
