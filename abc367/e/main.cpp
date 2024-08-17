#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int N;
    long long K;
    std::cin >> N >> K;

    std::vector<int> X(N), A(N);
    for (int i = 0; i < N; ++i) std::cin >> X[i];
    for (int i = 0; i < N; ++i) std::cin >> A[i];

    std::vector<int> result(N);
    std::vector<bool> visited(N, false);

    for (int i = 0; i < N; ++i) {
        if (!visited[i]) {
            std::vector<int> cycle;
            int current = i;
            while (!visited[current]) {
                visited[current] = true;
                cycle.push_back(current);
                current = X[current] - 1;
            }

            int cycle_length = cycle.size();
            long long rotations = K % cycle_length;

            for (int j = 0; j < cycle_length; ++j) {
                int from = cycle[j];
                int to = cycle[(j - rotations + cycle_length) % cycle_length];
                result[to] = A[from];
            }
        }
    }

    for (int i = 0; i < N; ++i) {
        std::cout << result[i] << (i == N-1 ? "\n" : " ");
    }

    return 0;
}
