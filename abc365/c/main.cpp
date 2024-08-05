#include <iostream>
#include <vector>
#include <algorithm>

bool canAfford(const std::vector<long long>& A, long long M, long long x) {
    long long total = 0;
    for (long long a : A) {
        total += std::min(x, a);
        if (total > M) return false;
    }
    return true;
}

int main() {
    int N;
    long long M;
    std::cin >> N >> M;

    std::vector<long long> A(N);
    for (int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    long long left = 0, right = 1e9 + 1;
    while (right - left > 1) {
        long long mid = (left + right) / 2;
        if (canAfford(A, M, mid)) {
            left = mid;
        } else {
            right = mid;
        }
    }

    if (left == 1e9) {
        std::cout << "infinite" << std::endl;
    } else {
        std::cout << left << std::endl;
    }

    return 0;
}
