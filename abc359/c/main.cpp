#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef __int128 i128;

i128 gcd(i128 a, i128 b) {
    return b ? gcd(b, a % b) : abs(a);
}

pair<i128, i128> reduce(i128 a, i128 b) {
    i128 g = gcd(a, b);
    return {a / g, b / g};
}

bool is_inside(i128 x, i128 y, i128 S_num, i128 S_den, i128 T_num, i128 T_den) {
    return x * S_den >= 0 && x * S_den <= S_num * 4 &&
           y * T_den >= 0 && y * T_den <= T_num * 4 * 1732050808LL;
}

ll count_tiles(i128 Si, i128 Sj, i128 Ti, i128 Tj) {
    if (Sj == 0) Sj = 1;
    if (Tj == 0) Tj = 1;

    auto S = reduce(Si, Sj);
    auto T = reduce(Ti, Tj);
    i128 S_num = S.first, S_den = S.second;
    i128 T_num = T.first, T_den = T.second;

    i128 count = 0;
    i128 i_max = (S_num * 4 / S_den + T_num * 4 / T_den) * 2;

    for (i128 i = -i_max; i <= i_max; ++i) {
        for (i128 j = -i_max; j <= i_max; ++j) {
            i128 x = (2 * (i + j) + ((i + j) % 2 ? -1 : 1)) * S_den - 2 * S_num;
            i128 y = (j - i) * 1732050808LL * T_den - 1000000000LL * T_num;
            if (is_inside(x, y, S_num, S_den, T_num, T_den)) {
                count++;
            }
        }
    }

    return (ll)count;
}

int main() {
    ll Si, Sj, Ti, Tj;
    char _;
    cin >> Si >> _ >> Sj >> Ti >> _ >> Tj;

    cout << count_tiles(Si, Sj, Ti, Tj) << endl;

    return 0;
}
