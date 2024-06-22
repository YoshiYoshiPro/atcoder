#include <iostream>
#include <string>
using namespace std;

int main() {
    int N;
    cin >> N;
    int count = 0;
    for (int i = 0; i < N; ++i) {
        string S;
        cin >> S;
        if (S == "Takahashi") {
            ++count;
        }
    }
    cout << count << endl;
    return 0;
}
