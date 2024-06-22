#include <iostream>
#include <vector>
#include <string>

using namespace std;

const int MOD = 998244353;

int solve(int N, int K, const string& S) {
    vector<vector<vector<long long>>> dp(N + 1, vector<vector<long long>>(K, vector<long long>(1 << K, 0)));
    dp[0][0][0] = 1;

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < K; ++j) {
            for (int mask = 0; mask < (1 << K); ++mask) {
                if (dp[i][j][mask] == 0) continue;

                for (char c : {'A', 'B'}) {
                    if (S[i] != '?' && S[i] != c) continue;

                    int new_mask = ((mask << 1) | (c == 'B' ? 1 : 0)) & ((1 << K) - 1);
                    int new_j = j + 1;

                    if (new_j == K) {
                        int rev_mask = 0;
                        for (int k = 0; k < K; ++k) {
                            rev_mask = (rev_mask << 1) | ((new_mask >> k) & 1);
                        }
                        if (new_mask == rev_mask) continue;
                        new_j = K - 1;
                    }

                    dp[i + 1][new_j][new_mask] += dp[i][j][mask];
                    dp[i + 1][new_j][new_mask] %= MOD;
                }
            }
        }
    }

    long long result = 0;
    for (int j = 0; j < K; ++j) {
        for (int mask = 0; mask < (1 << K); ++mask) {
            result += dp[N][j][mask];
            result %= MOD;
        }
    }
    return result;
}

int main() {
    int N, K;
    string S;
    cin >> N >> K;
    cin >> S;

    cout << solve(N, K, S) << endl;

    return 0;
}
