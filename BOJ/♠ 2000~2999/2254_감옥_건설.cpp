#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>
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

void sort_points(vector<Point>& points) {
    sort(points.begin(), points.end());

    for (size_t i = 1; i < points.size(); i++) {
        points[i].rx = points[i].x - points[0].x;
        points[i].ry = points[i].y - points[0].y;
    }

    sort(points.begin() + 1, points.end());
}

ll ccw(Point a, Point b, Point c) {
    return (b.x - a.x) * (c.y - a.y) - (c.x - a.x) * (b.y - a.y);
}

bool check_point_in_convex_hull(vector<Point>& points, Point target) {
    bool has_positive_ccw = false;
    bool has_negative_ccw = false;

    for (size_t i = 0; i < points.size(); i++) {
        ll next_index = (i + 1 == points.size()) ? 0 : i + 1;
        ll cur_ccw = ccw(points[i], points[next_index], target);

        if (cur_ccw > 0) {
            has_positive_ccw = true;
        } else if (cur_ccw < 0) {
            has_negative_ccw = true;
        } else {
            return false;
        }
    }

    return !(has_positive_ccw && has_negative_ccw);
}

bool make_convex_hull(vector<Point>& points, Point prison) {
    stack<int> S;
    S.push(0);
    S.push(1);

    for (int i = 2; i < points.size(); i++) {
        while (S.size() >= 2) {
            int second = S.top();
            S.pop();
            int first = S.top();

            if (ccw(points[first], points[second], points[i]) >= 0) {
                S.push(second);
                break;
            }
        }

        S.push(i);
    }

    vector<bool> is_used(points.size());
    vector<Point> convex_hull(S.size());

    while (!S.empty()) {
        int popped_index = S.top();
        S.pop();

        is_used[popped_index] = true;
        convex_hull[S.size()] = points[popped_index];
    }

    vector<Point> new_points;

    for (size_t i = 0; i < points.size(); i++) {
        if (!is_used[i]) {
            new_points.push_back(points[i]);
        }
    }

    points = move(new_points);

    if (!check_point_in_convex_hull(convex_hull, prison)) {
        return false;
    }

    return true;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N;
    cin >> N;

    Point prison;
    vector<Point> points(N);
    cin >> prison.x >> prison.y;

    for (int i = 0; i < N; i++) {
        cin >> points[i].x >> points[i].y;
    }

    int wall_level = 0;

    while (true) {
        if (points.size() < 3) {
            break;
        }

        sort_points(points);

        if (!make_convex_hull(points, prison)) {
            break;
        }

        wall_level += 1;
    }

    cout << wall_level;
}
