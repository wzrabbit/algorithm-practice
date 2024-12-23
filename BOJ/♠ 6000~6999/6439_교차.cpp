#include <iostream>
#include <vector>
using namespace std;

struct Point {
    int x, y;
};

int get_ccw(Point a, Point b, Point c) {
    return (b.x - a.x) * (c.y - a.y) - (c.x - a.x) * (b.y - a.y);
}

bool is_intersect(Point a, Point b, Point c, Point d) {
    int ccw1 = get_ccw(a, b, c) * get_ccw(a, b, d);
    int ccw2 = get_ccw(c, d, a) * get_ccw(c, d, b);

    if (ccw1 == 0 && ccw2 == 0) {
        return min(a.x, b.x) <= max(c.x, d.x) &&
               min(c.x, d.x) <= max(a.x, b.x) &&
               min(a.y, b.y) <= max(c.y, d.y) && min(c.y, d.y) <= max(a.y, b.y);
    }

    return ccw1 <= 0 && ccw2 <= 0;
}

bool is_point_inside_polygon(vector<Point> &polygon, Point point) {
    int positive_ccw_count = 0;
    int negative_ccw_count = 0;

    for (int i = 0; i < int(polygon.size()) - 2; i++) {
        int ccw = get_ccw(polygon[i], polygon[i + 1], point);

        if (ccw > 0) {
            positive_ccw_count += 1;
            continue;
        }

        if (ccw < 0) {
            negative_ccw_count += 1;
            continue;
        }

        return false;
    }

    return positive_ccw_count == int(polygon.size()) - 2 ||
           negative_ccw_count == int(polygon.size()) - 2;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int T;
    cin >> T;

    while (T--) {
        Point line_start, line_end;
        cin >> line_start.x >> line_start.y >> line_end.x >> line_end.y;

        Point a, b, c, d;
        cin >> a.x >> a.y >> c.x >> c.y;
        b.x = c.x;
        b.y = a.y;
        d.x = a.x;
        d.y = c.y;

        if (is_intersect(line_start, line_end, a, b) ||
            is_intersect(line_start, line_end, b, c) ||
            is_intersect(line_start, line_end, c, d) ||
            is_intersect(line_start, line_end, d, a)) {
            cout << "T\n";
            continue;
        }

        vector<Point> square = {a, b, c, d, a, b};

        if (is_point_inside_polygon(square, line_start) &&
            is_point_inside_polygon(square, line_end)) {
            cout << "T\n";
            continue;
        }

        cout << "F\n";
    }
}
