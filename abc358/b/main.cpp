#include <iostream>
#include <vector>

int main() {
    int N, A;
    std::cin >> N >> A;
    std::vector<int> T(N);

    for (int i = 0; i < N; ++i) {
        std::cin >> T[i];
    }

    int currentTime = 0;
    for (int i = 0; i < N; ++i) {
        if (currentTime < T[i]) {
            currentTime = T[i];
        }
        currentTime += A;
        std::cout << currentTime << std::endl;
    }

    return 0;
}
