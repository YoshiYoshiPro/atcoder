#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> A(9), B(8);
    for (int i = 0; i < 9; ++i) cin >> A[i];
    for (int i = 0; i < 8; ++i) cin >> B[i];

    int sumA = 0, sumB = 0;
    for (int i = 0; i < 9; ++i) sumA += A[i];
    for (int i = 0; i < 8; ++i) sumB += B[i];

    int requiredRuns = sumA - sumB + 1;
    cout << requiredRuns << endl;

    return 0;
}
