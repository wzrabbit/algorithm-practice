#include <algorithm>
#include <iomanip>
#include <iostream>
typedef long long ll;
typedef long double ld;
using namespace std;

struct Point {
    ll x, y;
};

Point triangle[5], apples[101];

ll ccw(Point a, Point b, Point c) {
    return (b.x - a.x) * (c.y - a.y) - (c.x - a.x) * (b.y - a.y);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    for (int i = 1; i <= 3; i++) {
        cin >> triangle[i].x >> triangle[i].y;
    }

    triangle[4] = triangle[1];

    ll triangle_ccw = ccw(triangle[1], triangle[2], triangle[3]);
    ld triangle_area = abs(triangle_ccw) / 2.0;
    bool is_triangle_ccw_positive = triangle_ccw > 0;

    cout << fixed << setprecision(1) << triangle_area << '\n';

    int N;
    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> apples[i].x >> apples[i].y;
    }

    int boj_apple_count = 0;

    for (int i = 1; i <= N; i++) {
        bool success = true;

        for (int j = 1; j <= 3; j++) {
            ld apple_ccw = ccw(apples[i], triangle[j], triangle[j + 1]);

            if (is_triangle_ccw_positive && apple_ccw < 0) {
                success = false;
                break;
            }

            if (!is_triangle_ccw_positive && apple_ccw > 0) {
                success = false;
                break;
            }
        }

        if (success) {
            boj_apple_count += 1;
        }
    }

    cout << boj_apple_count;
}
