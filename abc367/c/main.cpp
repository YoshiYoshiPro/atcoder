#include <iostream>
#include <vector>
#include <algorithm>

bool generateSequences(std::vector<int>& current, const std::vector<int>& R, int N, int K, int index, int sum) {
    if (index == N) {
        if (sum % K == 0) {
            for (int i = 0; i < N; ++i) {
                std::cout << current[i] << (i == N-1 ? "\n" : " ");
            }
            return true;
        }
        return false;
    }

    bool found = false;
    for (int i = 1; i <= R[index]; ++i) {
        current[index] = i;
        found |= generateSequences(current, R, N, K, index + 1, sum + i);
    }
    return found;
}

int main() {
    int N, K;
    std::cin >> N >> K;

    std::vector<int> R(N);
    for (int i = 0; i < N; ++i) {
        std::cin >> R[i];
    }

    std::vector<int> current(N);
    bool found = generateSequences(current, R, N, K, 0, 0);

    if (!found) {
        std::cout << std::endl;
    }

    return 0;
}
