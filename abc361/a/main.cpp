#include <iostream>
#include <vector>

int main() {
    int N, K, X;
    std::cin >> N >> K >> X;

    std::vector<int> A(N);
    for (int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::vector<int> B;
    for (int i = 0; i < N; i++) {
        B.push_back(A[i]);
        if (i == K - 1) {
            B.push_back(X);
        }
    }

    for (int i = 0; i < B.size(); i++) {
        std::cout << B[i];
        if (i < B.size() - 1) {
            std::cout << " ";
        }
    }
    std::cout << std::endl;

    return 0;
}
