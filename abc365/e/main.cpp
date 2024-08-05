#include <iostream>
#include <vector>

const int MOD = 998244353;

int main() {
    int N;
    std::cin >> N;

    std::vector<int> A(N);
    for (int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    long long result = 0;
    std::vector<int> count(30, 0);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 30; j++) {
            if (A[i] & (1 << j)) {
                result = (result + ((long long)(N - i) * (i + 1) - count[j]) * (1LL << j)) % MOD;
                count[j] = (count[j] + N - i) % MOD;
            } else {
                result = (result + count[j] * (1LL << j)) % MOD;
            }
        }
    }

    std::cout << result << std::endl;

    return 0;
}
