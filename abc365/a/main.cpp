#include <iostream>

int main() {
    int Y;
    std::cin >> Y;

    bool isLeapYear = false;

    if (Y % 4 == 0) {
        if (Y % 100 == 0) {
            if (Y % 400 == 0) {
                isLeapYear = true;
            }
        } else {
            isLeapYear = true;
        }
    }

    int days = isLeapYear ? 366 : 365;
    std::cout << days << std::endl;

    return 0;
}
