#include <iostream>
using namespace std;

int main() {
    int a, b, c, d, e, f;
    int g, h, i, j, k, l;
    cin >> a >> b >> c >> d >> e >> f;
    cin >> g >> h >> i >> j >> k >> l;

    int x_overlap = max(0, min(d, j) - max(a, g));
    int y_overlap = max(0, min(e, k) - max(b, h));
    int z_overlap = max(0, min(f, l) - max(c, i));

    int volume = x_overlap * y_overlap * z_overlap;

    if (volume > 0) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}
