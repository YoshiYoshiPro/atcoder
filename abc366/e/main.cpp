#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

const int OFFSET = 1000000;

int main() {
    int N, D;
    cin >> N >> D;

    vector<pair<int, int>> points(N);
    int min_a = 2 * OFFSET, max_a = 0, min_b = 2 * OFFSET, max_b = 0;

    for (int i = 0; i < N; i++) {
        int x, y;
        cin >> x >> y;
        int a = x + y;
        int b = x - y;
        points[i] = {a, b};
        min_a = min(min_a, a);
        max_a = max(max_a, a);
        min_b = min(min_b, b);
        max_b = max(max_b, b);
    }

    long long result = 0;
    for (int a = min_a - D; a <= max_a + D; a++) {
        for (int b = min_b - D; b <= max_b + D; b++) {
            if ((a + b) % 2 != 0) continue;
            int x = (a + b) / 2;
            int y = (a - b) / 2;
            long long total_dist = 0;
            for (const auto& p : points) {
                total_dist += abs(x - (p.first + p.second) / 2) + abs(y - (p.first - p.second) / 2);
                if (total_dist > D) break;
            }
            if (total_dist <= D) result++;
        }
    }

    cout << result << endl;

    return 0;
}
