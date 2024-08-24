#include <iostream>
#include <vector>

int main() {
    int N, K;
    std::cin >> N >> K;

    std::vector<int> cards(N);
    for (int i = 0; i < N; ++i) {
        std::cin >> cards[i];
    }

    for (int i = N - K; i < N; ++i) {
        std::cout << cards[i] << " ";
    }

    for (int i = 0; i < N - K; ++i) {
        std::cout << cards[i] << (i == N - K - 1 ? "" : " ");
    }

    std::cout << std::endl;

    return 0;
}
