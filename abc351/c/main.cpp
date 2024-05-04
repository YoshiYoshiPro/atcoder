#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> balls(N);
    for (int i = 0; i < N; i++) {
        cin >> balls[i];
    }

    vector<int> stack;

    for (int i = 0; i < N; i++) {
        int size = 1 << balls[i];

        while (!stack.empty() && stack.back() == size) {
            stack.pop_back();
            size *= 2;
        }

        stack.push_back(size);
    }

    cout << stack.size() << endl;

    return 0;
}
