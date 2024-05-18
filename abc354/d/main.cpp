#include <iostream>
using namespace std;

// 点 (x, y) が黒で塗られているかどうかを判定する関数
bool is_black(double x, double y) {
    return (static_cast<int>(x) + static_cast<int>(y)) % 2 == 1;
}

// 長方形内の黒で塗られた領域の面積を計算する関数
int calculate_black_area(int A, int B, int C, int D) {
    int black_count = 0;
    for (int x = A; x < C; ++x) {
        for (int y = B; y < D; ++y) {
            if (is_black(x + 0.5, y + 0.5)) {
                ++black_count;
            }
        }
    }
    return black_count * 2;
}

int main() {
    int A, B, C, D;
    cin >> A >> B >> C >> D;
    cout << calculate_black_area(A, B, C, D) << endl;
    return 0;
}
