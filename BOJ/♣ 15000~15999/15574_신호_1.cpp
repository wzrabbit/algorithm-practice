#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
typedef long long ll;
typedef long double ld;
using namespace std;

struct Point {
    ll x, y;
};

bool operator<(const Point& a, const Point& b) {
    return a.x < b.x;
}

Point points[1001];
ld dp[1001];

ld get_dist(Point& a, Point& b) {
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N;
    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> points[i].x >> points[i].y;
    }

    sort(points + 1, points + N + 1);

    for (int i = 2; i <= N; i++) {
        for (int j = 1; j <= i - 1; j++) {
            if (points[j].x < points[i].x) {
                dp[i] = max(dp[i], dp[j] + get_dist(points[j], points[i]));
            }
        }
    }

    ld max_dist = 0;

    for (int i = 2; i <= N; i++) {
        max_dist = max(max_dist, dp[i]);
    }

    cout << fixed << setprecision(7) << max_dist;
}
