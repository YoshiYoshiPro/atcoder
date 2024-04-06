#include <iostream>
#include <vector>
#include <queue>
#include <map>
using namespace std;

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

int main() {
    int H, W;
    cin >> H >> W;
    vector<string> grid(H);
    for (int i = 0; i < H; ++i) cin >> grid[i];

    int sx, sy, gx, gy;
    map<pair<int, int>, int> pills;
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            if (grid[i][j] == 'S') {
                sx = i;
                sy = j;
            } else if (grid[i][j] == 'T') {
                gx = i;
                gy = j;
            }
        }
    }

    int N;
    cin >> N;
    for (int i = 0; i < N; ++i) {
        int r, c, e;
        cin >> r >> c >> e;
        --r; --c;
        pills[{r, c}] = e;
    }

    vector<vector<int>> energy(H, vector<int>(W, -1));
    queue<tuple<int, int, int>> q;
    q.push({sx, sy, 0});
    energy[sx][sy] = 0;

    while (!q.empty()) {
        auto [x, y, e] = q.front();
        q.pop();

        if (x == gx && y == gy) {
            cout << "Yes" << endl;
            return 0;
        }

        for (int i = 0; i < 4; ++i) {
          int nx = x + dx[i], ny = y + dy[i];
          if (nx < 0 || nx >= H || ny < 0 || ny >= W) continue;
          if (grid[nx][ny] == '#' || e <= 0) continue;
          if (energy[nx][ny] < e - 1) {
            energy[nx][ny] = e - 1;
            q.push({nx, ny, e - 1});
          }
        }
    }


    return 0;
}
