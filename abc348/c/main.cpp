#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int main() {
    int N;
    cin >> N;
    map<int, vector<int>> beans;
    for (int i = 0; i < N; ++i) {
        int A, C;
        cin >> A >> C;
        beans[C].push_back(A);
    }

    int maxMinDeliciousness = 0;
    for (auto &pair : beans) {
        int minDeliciousness = *min_element(pair.second.begin(), pair.second.end());
        maxMinDeliciousness = max(maxMinDeliciousness, minDeliciousness);
    }

    cout << maxMinDeliciousness << endl;
    return 0;
}
