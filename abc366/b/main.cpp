#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
    int N;
    std::cin >> N;

    std::vector<std::string> S(N);
    int M = 0;
    for (int i = 0; i < N; i++) {
        std::cin >> S[i];
        M = std::max(M, static_cast<int>(S[i].length()));
    }

    std::vector<std::string> T(M, std::string(N, '*'));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < S[i].length(); j++) {
            T[j][N-1-i] = S[i][j];
        }
    }

    for (const auto& row : T) {
        std::string trimmed = row;
        while (!trimmed.empty() && trimmed.back() == '*') {
            trimmed.pop_back();
        }
        std::cout << trimmed << std::endl;
    }

    return 0;
}
