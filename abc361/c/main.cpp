#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    sort(A.begin(), A.end());

    int remaining = N - K;
    int min_diff = INT_MAX;

    for (int i = 0; i <= K; ++i) {
        int current_diff = A[i + remaining - 1] - A[i];
        min_diff = min(min_diff, current_diff);
    }

    cout << min_diff << endl;

    return 0;
}
