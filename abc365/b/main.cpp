#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int N;
    std::cin >> N;

    std::vector<std::pair<int, int>> A(N);
    for (int i = 0; i < N; i++) {
        std::cin >> A[i].first;
        A[i].second = i + 1;
    }

    std::sort(A.begin(), A.end(), std::greater<std::pair<int, int>>());

    std::cout << A[1].second << std::endl;

    return 0;
}
