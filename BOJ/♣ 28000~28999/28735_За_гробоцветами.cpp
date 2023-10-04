#include <algorithm>
#include <iostream>
using namespace std;

int get_gcd(int x, int y) {
    if (x == 0) return y;
    if (y == 0) return x;
    if (x % y == 0) return y;
    return get_gcd(y, x % y);
}

struct Hunter {
    int x, y, n;
};

bool hunter_sort(Hunter a, Hunter b) {
    return a.x < b.x;
}

Hunter hunters[100001];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N;
    cin >> N;

    for (int i = 1; i <= N; i++) {
        int x, y;
        cin >> x >> y;

        hunters[i] = {x, y, i};
    }

    sort(hunters + 1, hunters + N + 1, hunter_sort);

    int prev_x;
    int prev_y;

    for (int i = 1; i <= N - 1; i++) {
        int diff_x = hunters[i + 1].x - hunters[i].x;
        int diff_y = hunters[i + 1].y - hunters[i].y;
        int gcd = get_gcd(diff_x, diff_y);

        if (gcd == 0) {
            diff_x = 1;
            diff_y = 0;
        } else {
            diff_x /= gcd;
            diff_y /= gcd;
        }

        if (i == 1) {
            prev_x = diff_x;
            prev_y = diff_y;
            continue;
        }

        if (prev_x != diff_x || prev_y != diff_y) {
            cout << "Yes" << '\n'
                 << hunters[i - 1].n << ' ' << hunters[i].n << ' ' << hunters[i + 1].n;
            return 0;
        }
    }

    cout << "No";
}