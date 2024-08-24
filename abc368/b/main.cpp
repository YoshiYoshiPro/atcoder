#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int N;
    std::cin >> N;

    std::vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        std::cin >> A[i];
    }

    int operations = 0;
    while (true) {
        int positive_count = std::count_if(A.begin(), A.end(), [](int x) { return x > 0; });

        if (positive_count <= 1) {
            break;
        }

        std::sort(A.begin(), A.end(), std::greater<int>());
        std::sort(A.begin(), A.end(), std::greater<int>());

        A[0]--;
        A[1]--;

        operations++;
    }

    std::cout << operations << std::endl;

    return 0;
}
