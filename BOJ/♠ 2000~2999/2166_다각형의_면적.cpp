#include <algorithm>
#include <iomanip>
#include <iostream>
typedef long long ll;
typedef long double ld;
using namespace std;

struct Point {
    ll x, y;
};

Point points[10001];

ld get_triangle_score(Point a, Point b, Point c) {
    return (a.x * b.y + b.x * c.y + c.x * a.y - b.x * a.y - c.x * b.y - a.x * c.y) / 2.0;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N;
    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> points[i].x >> points[i].y;
    }

    ld total_area = 0;

    for (int i = 2; i <= N - 1; i++) {
        total_area += get_triangle_score(points[1], points[i], points[i + 1]);
    }

    total_area = abs(total_area);

    cout << fixed << setprecision(1) << total_area;
}
