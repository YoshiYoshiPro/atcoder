#include <iostream>
#include <vector>
#include <string>
#include <bitset>

int main() {
    int N, M;
    std::cin >> N >> M;
    std::vector<std::string> S(N);

    for (int i = 0; i < N; ++i) {
        std::cin >> S[i];
    }

    int min_stalls = N;

    for (int mask = 1; mask < (1 << N); ++mask) {
        std::bitset<10> covered;
        int count = 0;

        for (int i = 0; i < N; ++i) {
            if (mask & (1 << i)) {
                count++;
                for (int j = 0; j < M; ++j) {
                    if (S[i][j] == 'o') {
                        covered.set(j);
                    }
                }
            }
        }


        if (covered.count() == M) {
            min_stalls = std::min(min_stalls, count);
        }
    }

    std::cout << min_stalls << std::endl;

    return 0;
}
