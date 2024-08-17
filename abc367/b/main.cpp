#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>

int main() {
    double X;
    std::cin >> X;
    std::ostringstream oss;
    oss << std::fixed << std::setprecision(3) << X;
    std::string result = oss.str();

    result.erase(result.find_last_not_of('0') + 1, std::string::npos);

    if (result.back() == '.') {
        result.pop_back();
    }

    std::cout << result << std::endl;

    return 0;
}
