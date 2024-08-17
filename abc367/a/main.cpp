#include <iostream>

int main() {
    int A, B, C;
    std::cin >> A >> B >> C;

    bool canShout = false;

    if (B < C) {
        canShout = (A >= C || A < B);
    } else {
        canShout = (A >= C && A < B);
    }

    std::cout << (canShout ? "Yes" : "No") << std::endl;

    return 0;
}
