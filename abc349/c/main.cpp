#include <iostream>
#include <string>
using namespace std;

bool isAirportCode(const string& S, const string& T) {
    if (T.back() == 'X') {
        string T_sub = T.substr(0, 2);
        int j = 0;
        for (int i = 0; i < S.size() && j < T_sub.size(); ++i) {
            if (toupper(S[i]) == T_sub[j]) {
                ++j;
            }
        }
        return j == T_sub.size();
    } else {
        int j = 0;
        for (int i = 0; i < S.size() && j < T.size(); ++i) {
            if (toupper(S[i]) == T[j]) {
                ++j;
            }
        }
        return j == T.size();
    }
}

int main() {
    string S, T;
    cin >> S >> T;
    if (isAirportCode(S, T)) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}
