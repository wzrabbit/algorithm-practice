#include <algorithm>
#include <iomanip>
#include <iostream>
#include <vector>
typedef long long ll;
typedef long double ld;
using namespace std;

struct Point {
    ld x, y, dx, dy;
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

vector<Point> polygon1, polygon2;
int N, M;

ld get_ccw(Point a, Point b, Point c) {
    return (b.x - a.x) * (c.y - a.y) - (c.x - a.x) * (b.y - a.y);
}

int get_ccw_sign(Point a, Point b, Point c) {
    ld ccw = get_ccw(a, b, c);

    if (ccw > 0) {
        return 1;
    }

    if (ccw < 0) {
        return -1;
    }

    return 0;
}

bool is_intersect(Point a, Point b, Point c, Point d) {
    int ccw1 = get_ccw_sign(a, b, c) * get_ccw_sign(a, b, d);
    int ccw2 = get_ccw_sign(c, d, a) * get_ccw_sign(c, d, b);

    if (ccw1 == 0 && ccw2 == 0) {
        return min(a.x, b.x) <= max(c.x, d.x) &&
               min(c.x, d.x) <= max(a.x, b.x) &&
               min(a.y, b.y) <= max(c.y, d.y) && min(c.y, d.y) <= max(a.y, b.y);
    }

    return ccw1 <= 0 && ccw2 <= 0;
}

bool is_point_inside_polygon(vector<Point> &polygon, Point point) {
    for (int i = 0; i < int(polygon.size()) - 2; i++) {
        if (get_ccw_sign(polygon[i], polygon[i + 1], point) <= 0) {
            return false;
        }
    }

    return true;
}

Point get_intersect_point(Point a, Point b, Point c, Point d) {
    ld det = (a.x - b.x) * (c.y - d.y) - (a.y - b.y) * (c.x - d.x);
    ld x = ((a.x * b.y - a.y * b.x) * (c.x - d.x) -
            (a.x - b.x) * (c.x * d.y - c.y * d.x)) /
           det;
    ld y = ((a.x * b.y - a.y * b.x) * (c.y - d.y) -
            (a.y - b.y) * (c.x * d.y - c.y * d.x)) /
           det;
    return Point{x, y};
}

ld get_triangle_area(Point a, Point b, Point c) {
    return (a.x * b.y + b.x * c.y + c.x * a.y - b.x * a.y - c.x * b.y -
            a.x * c.y) /
           2.0;
}

ld get_polygon_area(vector<Point> &polygon) {
    ld polygon_area = 0;

    for (int i = 1; i < int(polygon.size()) - 1; i++) {
        polygon_area +=
            get_triangle_area(polygon[0], polygon[i], polygon[i + 1]);
    }

    return polygon_area;
}

void sort_polygon(vector<Point> &polygon) {
    sort(polygon.begin(), polygon.end());

    for (size_t i = 1; i < polygon.size(); i++) {
        polygon[i].dx = polygon[i].x - polygon[0].x;
        polygon[i].dy = polygon[i].y - polygon[0].y;
    }

    sort(polygon.begin(), polygon.end());
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cout << fixed << setprecision(15);

    cin >> N >> M;
    polygon1.resize(N);
    polygon2.resize(M);

    if (N <= 2 || M <= 2) {
        cout << 0;
        return 0;
    }

    for (int i = 0; i < N; i++) {
        cin >> polygon1[i].x >> polygon1[i].y;
    }

    for (int i = 0; i < M; i++) {
        cin >> polygon2[i].x >> polygon2[i].y;
    }

    for (int i = 0; i < 2; i++) {
        polygon1.push_back(polygon1[i]);
        polygon2.push_back(polygon2[i]);
    }

    vector<Point> inner_points;

    for (int i = 0; i < N; i++) {
        if (is_point_inside_polygon(polygon2, polygon1[i])) {
            inner_points.push_back(polygon1[i]);
        }
    }

    for (int i = 0; i < M; i++) {
        if (is_point_inside_polygon(polygon1, polygon2[i])) {
            inner_points.push_back(polygon2[i]);
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (is_intersect(polygon1[i], polygon1[i + 1], polygon2[j],
                             polygon2[j + 1])) {
                Point intersect_point = get_intersect_point(
                    polygon1[i], polygon1[i + 1], polygon2[j], polygon2[j + 1]);
                inner_points.push_back(intersect_point);
            }
        }
    }

    sort_polygon(inner_points);
    cout << get_polygon_area(inner_points);
}
