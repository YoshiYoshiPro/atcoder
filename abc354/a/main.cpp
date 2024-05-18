#include <iostream>
using namespace std;

int main() {
    long long H;
    cin >> H;

    long long height = 0;
    int days = 0;

    while (height <= H) {
        height = (1LL << (days + 1)) - 1;
        days++;
    }

    cout << days << endl;
    return 0;
}
