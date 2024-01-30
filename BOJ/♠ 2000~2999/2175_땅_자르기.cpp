#include <iomanip>
#include <iostream>
#include <vector>
using namespace std;

struct Point {
    double x, y;
};

double ccw(Point a, Point b, Point c) {
    return (b.x - a.x) * (c.y - a.y) - (c.x - a.x) * (b.y - a.y);
}

double get_triangle_area(Point a, Point b, Point c) {
    return abs(ccw(a, b, c)) / 2;
}

double get_square_area(Point a, Point b, Point c, Point d) {
    return abs(ccw(a, b, c) + ccw(a, c, d)) / 2;
}

int main() {
    Point a, b, c, d;
    cin >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y >> d.x >> d.y;

    double total_area = get_square_area(a, b, c, d);

    vector<Point> points = {
        a,
        b,
        c,
        d,
        {(a.x + b.x) / 2, (a.y + b.y) / 2},
        {(b.x + c.x) / 2, (b.y + c.y) / 2},
        {(c.x + d.x) / 2, (c.y + d.y) / 2},
        {(d.x + a.x) / 2, (d.y + a.y) / 2},
    };

    vector<double> sliced_areas = {
        get_triangle_area(points[0], points[4], points[7]),
        get_triangle_area(points[1], points[4], points[5]),
        get_triangle_area(points[2], points[5], points[6]),
        get_triangle_area(points[3], points[6], points[7]),
        get_triangle_area(points[0], points[1], points[7]),
        get_triangle_area(points[0], points[1], points[5]),
        get_triangle_area(points[2], points[3], points[5]),
        get_triangle_area(points[2], points[3], points[7]),
        get_triangle_area(points[1], points[4], points[6]),
        get_triangle_area(points[2], points[4], points[6]),
        get_triangle_area(points[0], points[3], points[4]),
        get_triangle_area(points[2], points[3], points[6]),
        get_triangle_area(points[0], points[1], points[3]),
        get_triangle_area(points[0], points[2], points[3]),
        get_square_area(points[0], points[1], points[5], points[7]),
        get_square_area(points[1], points[2], points[6], points[4])};

    double best_sliced_area = 0;

    for (int i = 0; i < 16; i++) {
        best_sliced_area = max(
            best_sliced_area,
            min(sliced_areas[i], total_area - sliced_areas[i]));
    }

    cout << fixed << setprecision(4) << best_sliced_area << ' ' << total_area - best_sliced_area;
}
