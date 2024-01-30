#include <iomanip>
#include <iostream>
using namespace std;

struct Point {
    int x, y;
};

int ccw(Point a, Point b, Point c) {
    return (b.x - a.x) * (c.y - a.y) - (c.x - a.x) * (b.y - a.y);
}

double get_square_area(Point a, Point b, Point c, Point d) {
    return abs(ccw(a, b, c) + ccw(a, c, d)) / 2.0;
}

int main() {
    int N;
    cin >> N;

    Point a, b, c, d;
    cin >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y >> d.x >> d.y;

    cout << fixed << setprecision(10) << get_square_area(a, b, c, d) / N;
}
