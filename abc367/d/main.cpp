#include <iostream>
#include <vector>
#include <unordered_map>

int main() {
    int N, M;
    std::cin >> N >> M;

    std::vector<long long> A(N);
    for (int i = 0; i < N; ++i) {
        std::cin >> A[i];
    }

    std::unordered_map<long long, int> modCount;
    modCount[0] = 1;
    long long prefixSum = 0;
    long long count = 0;

    for (int i = 0; i < 2*N; ++i) {
        prefixSum += A[i % N];
        long long mod = prefixSum % M;
        if (i < N) {
            count += modCount[mod];
        }
        modCount[mod]++;
    }

    std::cout << count << std::endl;

    return 0;
}
