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
        return a.rx * b.ry < a.ry * b.rx;
    }

    if (a.y != b.y) {
        return a.y > b.y;
    }

    return a.x < b.x;
}

ll ccw(Point a, Point b, Point c) {
    return (b.x - a.x) * (c.y - a.y) - (c.x - a.x) * (b.y - a.y);
}

void print_convex_hull(vector<Point> points) {
    stack<int> S;
    S.push(0);
    S.push(1);

    for (size_t i = 2; i < points.size(); i++) {
        while (S.size() >= 2) {
            ll second = S.top();
            S.pop();
            ll first = S.top();

            if (ccw(points[first], points[second], points[i]) < 0) {
                S.push(second);
                break;
            }
        }

        S.push(i);
    }

    vector<int> answer(S.size());

    while (!S.empty()) {
        int popped = S.top();
        S.pop();
        answer[S.size()] = popped;
    }

    cout << answer.size() << '\n';

    for (size_t i = 0; i < answer.size(); i++) {
        cout << points[answer[i]].x << ' ' << points[answer[i]].y << '\n';
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;

        vector<Point> points(N);

        for (int i = 0; i < N; i++) {
            cin >> points[i].x >> points[i].y;
        }

        sort(points.begin(), points.end());

        for (size_t i = 1; i < points.size(); i++) {
            points[i].rx = points[i].x - points[0].x;
            points[i].ry = points[i].y - points[0].y;
        }

        sort(points.begin() + 1, points.end());

        print_convex_hull(points);
    }
}