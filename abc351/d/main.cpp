#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int H, W;
vector<string> S;
vector<vector<bool>> visited;

bool canMove(int i, int j) {
    if (i > 0 && S[i - 1][j] == '#') return false;
    if (i < H - 1 && S[i + 1][j] == '#') return false;
    if (j > 0 && S[i][j - 1] == '#') return false;
    if (j < W - 1 && S[i][j + 1] == '#') return false;
    return true;
}

int dfs(int i, int j) {
    if (i < 0 || i >= H || j < 0 || j >= W || S[i][j] == '#' || visited[i][j]) {
        return 0;
    }
    visited[i][j] = true;
    int count = 1;
    if (!canMove(i, j)) {
        return count;
    }
    count += dfs(i - 1, j); // 上
    count += dfs(i + 1, j); // 下
    count += dfs(i, j - 1); // 左
    count += dfs(i, j + 1); // 右
    return count;
}

int main() {
    cin >> H >> W;
    S.resize(H);
    for (int i = 0; i < H; i++) {
        cin >> S[i];
    }

    int maxFreedom = 0;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (S[i][j] == '.') {
                visited.assign(H, vector<bool>(W, false));
                maxFreedom = max(maxFreedom, dfs(i, j));
            }
        }
    }

    cout << maxFreedom << endl;
    return 0;
}
