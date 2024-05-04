#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    vector<int> P(N);
    for (int i = 0; i < N; i++) {
        cin >> P[i];
    }

    int ans = N;
    for (int i = 0; i <= N - K; i++) {
        int min_val = *min_element(P.begin() + i, P.begin() + i + K);
        int max_val = *max_element(P.begin() + i, P.begin() + i + K);

        if (max_val - min_val == K - 1) {
            int left = find(P.begin(), P.end(), min_val) - P.begin();
            int right = find(P.begin(), P.end(), max_val) - P.begin();
            ans = min(ans, right - left);
        }
    }

    cout << ans << endl;
    return 0;
}
