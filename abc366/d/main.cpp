#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<vector<vector<long long>>> A(N+1, vector<vector<long long>>(N+1, vector<long long>(N+1, 0)));
    vector<vector<vector<long long>>> sum(N+1, vector<vector<long long>>(N+1, vector<long long>(N+1, 0)));

    for(int x = 1; x <= N; x++) {
        for(int y = 1; y <= N; y++) {
            for(int z = 1; z <= N; z++) {
                cin >> A[x][y][z];
            }
        }
    }

    for(int x = 1; x <= N; x++) {
        for(int y = 1; y <= N; y++) {
            for(int z = 1; z <= N; z++) {
                sum[x][y][z] = A[x][y][z] + sum[x-1][y][z] + sum[x][y-1][z] + sum[x][y][z-1]
                               - sum[x-1][y-1][z] - sum[x-1][y][z-1] - sum[x][y-1][z-1]
                               + sum[x-1][y-1][z-1];
            }
        }
    }

    int Q;
    cin >> Q;

    while(Q--) {
        int x1, x2, y1, y2, z1, z2;
        cin >> x1 >> x2 >> y1 >> y2 >> z1 >> z2;
        long long result = sum[x2][y2][z2] - sum[x1-1][y2][z2] - sum[x2][y1-1][z2] - sum[x2][y2][z1-1]
                           + sum[x1-1][y1-1][z2] + sum[x1-1][y2][z1-1] + sum[x2][y1-1][z1-1]
                           - sum[x1-1][y1-1][z1-1];
        cout << result << endl;
    }

    return 0;
}
