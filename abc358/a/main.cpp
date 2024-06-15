#include <iostream>
#include <string>

int main() {
    std::string S, T;
    std::cin >> S >> T;

    if (S == "AtCoder" && T == "Land") {
        std::cout << "Yes" << std::endl;
    } else {
        std::cout << "No" << std::endl;
    }

    return 0;
}
