#include <algorithm>
#include <iostream>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int R, C;
    cin >> R >> C;

    if (R == 1) {
        cout << 1;
        return 0;
    }

    if (R == 2) {
        cout << min(4, (C + 1) / 2);
        return 0;
    }

    if (C <= 6) {
        cout << min(4, C);
        return 0;
    }

    cout << C - 2;
}