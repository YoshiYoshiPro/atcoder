#include <iostream>
#include <vector>
using namespace std;

vector<pair<long long, long long>> solve(long long L, long long R) {
    vector<pair<long long, long long>> res;
    for (int i = 60; i >= 0; i--) {
        long long mask = 1LL << i;
        if ((L & mask) != (R & mask)) {
            if ((L & mask) == 0) {
                long long nextL = L | mask;
                if (nextL < R) {
                    res.push_back({L, nextL});
                    L = nextL;
                }
            }
        }
    }
    if (L < R) {
        res.push_back({L, R});
    }
    return res;
}

int main() {
    long long L, R;
    cin >> L >> R;
    auto res = solve(L, R);
    cout << res.size() << endl;
    for (auto [l, r] : res) {
        cout << l << " " << r << endl;
    }
    return 0;
}
