#include <iostream>
#include <string>
#include <queue>
#include <unordered_set>
#include <vector>

struct State {
    std::string stones;
    int moves;
};

int bfs(const std::string& start, const std::string& target) {
    std::queue<State> q;
    std::unordered_set<std::string> visited;

    q.push({start + "..", 0});
    visited.insert(start + "..");

    while (!q.empty()) {
        State current = q.front();
        q.pop();

        if (current.stones.substr(0, target.length()) == target) {
            return current.moves;
        }

        for (int i = 0; i < current.stones.length() - 1; ++i) {
            if (current.stones[i] != '.' && current.stones[i+1] != '.') {
                for (int j = 0; j < current.stones.length() - 1; ++j) {
                    if (current.stones[j] == '.' && current.stones[j+1] == '.') {
                        std::string next = current.stones;
                        next[j] = current.stones[i];
                        next[j+1] = current.stones[i+1];
                        next[i] = '.';
                        next[i+1] = '.';

                        if (visited.find(next) == visited.end()) {
                            q.push({next, current.moves + 1});
                            visited.insert(next);
                        }
                        break;
                    }
                }
            }
        }
    }

    return -1;
}

int main() {
    int N;
    std::string S, T;

    std::cin >> N >> S >> T;

    int result = bfs(S, T);
    std::cout << result << std::endl;

    return 0;
}
