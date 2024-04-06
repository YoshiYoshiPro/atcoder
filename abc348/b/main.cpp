#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<pair<int, int>> points(N);
    for (int i = 0; i < N; ++i) {
        cin >> points[i].first >> points[i].second;
    }

    for (int i = 0; i < N; ++i) {
        double maxDist = 0;
        int maxIndex = 0;
        for (int j = 0; j < N; ++j) {
            if (i == j) continue;
            double dist = pow(points[i].first - points[j].first, 2) + pow(points[i].second - points[j].second, 2);
            if (dist > maxDist) {
                maxDist = dist;
                maxIndex = j;
            }
        }
        cout << maxIndex + 1 << endl;
    }
    return 0;
}
