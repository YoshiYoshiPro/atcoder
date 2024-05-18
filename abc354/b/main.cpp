#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct User {
    string name;
    int rate;
};

int main() {
    int N;
    cin >> N;
    vector<User> users(N);
    long long totalRate = 0;

    for (int i = 0; i < N; ++i) {
        cin >> users[i].name >> users[i].rate;
        totalRate += users[i].rate;
    }

    sort(users.begin(), users.end(), [](const User &a, const User &b) {
        return a.name < b.name;
    });

    int winnerIndex = totalRate % N;
    cout << users[winnerIndex].name << endl;

    return 0;
}
