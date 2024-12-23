#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>
typedef long long ll;
using namespace std;

struct Point {
    ll x, y, dx, dy;
};

bool operator<(const Point &a, const Point &b) {
    if (a.dx * b.dy != a.dy * b.dx) {
        return a.dx * b.dy > a.dy * b.dx;
    }

    if (a.y != b.y) {
        return a.y < b.y;
    }

    return a.x < b.x;
}

ll get_ccw(Point a, Point b, Point c) {
    return (b.x - a.x) * (c.y - a.y) - (c.x - a.x) * (b.y - a.y);
}

bool is_point_inside_polygon(vector<Point> &polygon, Point point) {
    for (int i = 0; i < int(polygon.size()) - 2; i++) {
        if (get_ccw(polygon[i], polygon[i + 1], point) <= 0) {
            return false;
        }
    }

    return true;
}

bool is_intersect(Point a, Point b, Point c, Point d) {
    ll ccw1 = ll(get_ccw(a, b, c)) * get_ccw(a, b, d);
    ll ccw2 = ll(get_ccw(c, d, a)) * get_ccw(c, d, b);

    if (ccw1 == 0 && ccw2 == 0) {
        return min(a.x, b.x) <= max(c.x, d.x) &&
               min(c.x, d.x) <= max(a.x, b.x) &&
               min(a.y, b.y) <= max(c.y, d.y) && min(c.y, d.y) <= max(a.y, b.y);
    }

    return ccw1 <= 0 && ccw2 <= 0;
}

void sort_polygon(vector<Point> &polygon) {
    sort(polygon.begin(), polygon.end());

    for (size_t i = 1; i < polygon.size(); i++) {
        polygon[i].dx = polygon[i].x - polygon[0].x;
        polygon[i].dy = polygon[i].y - polygon[0].y;
    }

    sort(polygon.begin(), polygon.end());
}

vector<Point> get_convex_hull(vector<Point> polygon) {
    if (polygon.size() <= 2) {
        return polygon;
    }

    stack<int> S;
    S.push(0);
    S.push(1);

    for (size_t i = 2; i < polygon.size(); i++) {
        while (S.size() >= 2) {
            int second = S.top();
            S.pop();
            int first = S.top();

            if (get_ccw(polygon[first], polygon[second], polygon[i]) > 0) {
                S.push(second);
                break;
            }
        }

        S.push(i);
    }

    vector<Point> convex_hull;

    while (!S.empty()) {
        int cur = S.top();
        S.pop();
        convex_hull.push_back(polygon[cur]);
    }

    reverse(convex_hull.begin(), convex_hull.end());

    return convex_hull;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int T;
    cin >> T;

    while (T--) {
        int N, M;
        cin >> N >> M;

        vector<Point> polygon1, polygon2;
        polygon1.resize(N);
        polygon2.resize(M);

        for (int i = 0; i < N; i++) {
            cin >> polygon1[i].x >> polygon1[i].y;
        }

        for (int i = 0; i < M; i++) {
            cin >> polygon2[i].x >> polygon2[i].y;
        }

        sort_polygon(polygon1);
        sort_polygon(polygon2);

        polygon1 = get_convex_hull(polygon1);
        polygon2 = get_convex_hull(polygon2);

        polygon1.push_back(polygon1[0]);
        polygon1.push_back(polygon1[1]);
        polygon2.push_back(polygon2[0]);
        polygon2.push_back(polygon2[1]);

        bool fail = false;

        for (int i = 0; i < int(polygon1.size()) - 2; i++) {
            if (is_point_inside_polygon(polygon2, polygon1[i])) {
                fail = true;
                break;
            }
        }

        for (int i = 0; i < int(polygon2.size()) - 2; i++) {
            if (is_point_inside_polygon(polygon1, polygon2[i])) {
                fail = true;
                break;
            }
        }

        for (int i = 0; i < int(polygon1.size()) - 2; i++) {
            for (int j = 0; j < int(polygon2.size()) - 2; j++) {
                if (is_intersect(polygon1[i], polygon1[i + 1], polygon2[j],
                                 polygon2[j + 1])) {
                    fail = true;
                    break;
                }
            }
        }

        if (fail) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
        }
    }
}
