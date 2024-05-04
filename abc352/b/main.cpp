#include <iostream>
#include <vector>
using namespace std;

int main() {
    string S, T;
    cin >> S >> T;

    vector<int> positions;
    int j = 0;
    for (int i = 0; i < S.size(); ++i) {
        while (S[i] != T[j]) {
            j++;
        }
        positions.push_back(j + 1);
        j++;
    }

    for (int i = 0; i < positions.size(); ++i) {
        if (i > 0) cout << " ";
        cout << positions[i];
    }
    cout << endl;

    return 0;
}
