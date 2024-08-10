#include <iostream>
#include <unordered_map>

int main() {
    int Q;
    std::cin >> Q;

    std::unordered_map<int, int> bag;
    int unique_count = 0;

    for (int i = 0; i < Q; i++) {
        int query_type;
        std::cin >> query_type;

        if (query_type == 1) {
            int x;
            std::cin >> x;
            if (bag[x] == 0) {
                unique_count++;
            }
            bag[x]++;
        } else if (query_type == 2) {
            int x;
            std::cin >> x;
            bag[x]--;
            if (bag[x] == 0) {
                unique_count--;
            }
        } else if (query_type == 3) {
            std::cout << unique_count << std::endl;
        }
    }

    return 0;
}
