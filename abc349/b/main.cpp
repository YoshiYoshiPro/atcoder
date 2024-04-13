#include <iostream>
#include <map>
using namespace std;

int main() {
    string S;
    cin >> S;
    map<char, int> count;
    for (char c : S) {
        count[c]++;
    }
    map<int, int> freq;
    for (auto p : count) {
        freq[p.second]++;
    }
    for (auto p : freq) {
        if (p.second != 2 && p.second != 0) {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}
