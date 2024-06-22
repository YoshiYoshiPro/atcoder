#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> A(2 * N);
    for (int i = 0; i < 2 * N; ++i) {
        cin >> A[i];
    }

    int count = 0;
    for (int i = 1; i <= N; ++i) {
        int first = -1, second = -1;
        for (int j = 0; j < 2 * N; ++j) {
            if (A[j] == i) {
                if (first == -1) {
                    first = j;
                } else {
                    second = j;
                    break;
                }
            }
        }
        if (second - first == 2) {
            ++count;
        }
    }

    cout << count << endl;
    return 0;
}
