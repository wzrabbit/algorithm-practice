#include <algorithm>
#include <iostream>
#include <stack>
typedef long long ll;
using namespace std;

struct Point {
    ll x, y, rx, ry;
};

bool operator<(const Point& a, const Point& b) {
    if (a.rx * b.ry != a.ry * b.rx) {
        return a.rx * b.ry > a.ry * b.rx;
    }

    if (a.y != b.y) {
        return a.y < b.y;
    }

    return a.x < b.x;
}

Point points[100001];
int N;

ll ccw(Point a, Point b, Point c) {
    return (b.x - a.x) * (c.y - a.y) - (c.x - a.x) * (b.y - a.y);
}

ll get_convex_hull_size() {
    stack<int> S;
    S.push(1);
    S.push(2);

    for (int i = 3; i <= N; i++) {
        while (S.size() >= 2) {
            ll second = S.top();
            S.pop();
            ll first = S.top();

            if (ccw(points[first], points[second], points[i]) > 0) {
                S.push(second);
                break;
            }
        }

        S.push(i);
    }

    return S.size();
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> points[i].x >> points[i].y;
    }

    sort(points + 1, points + N + 1);

    for (int i = 2; i <= N; i++) {
        points[i].rx = points[i].x - points[1].x;
        points[i].ry = points[i].y - points[1].y;
    }

    sort(points + 2, points + N + 1);

    cout << get_convex_hull_size();
}
