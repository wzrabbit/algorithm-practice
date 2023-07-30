#include <algorithm>
#include <iomanip>
#include <iostream>
using namespace std;

struct Position {
    double x, y, speed_x, speed_y;
};

Position mice[51];
int N;

double get_smallest_square(double cur_time) {
    double min_x = 1e7;
    double min_y = 1e7;
    double max_x = -1e7;
    double max_y = -1e7;

    for (int i = 1; i <= N; i++) {
        min_x = min(min_x, mice[i].x + cur_time * mice[i].speed_x);
        min_y = min(min_y, mice[i].y + cur_time * mice[i].speed_y);
        max_x = max(max_x, mice[i].x + cur_time * mice[i].speed_x);
        max_y = max(max_y, mice[i].y + cur_time * mice[i].speed_y);
    }

    double result = max(max_x - min_x, max_y - min_y);

    return result;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> N;

    for (int i = 1; i <= N; i++) {
        double x, y, speed_x, speed_y;
        cin >> x >> y >> speed_x >> speed_y;

        mice[i] = {x, y, speed_x, speed_y};
    }

    double start = 0.0;
    double end = 2000.0;

    for (int i = 1; i <= 85; i++) {
        double p = (start * 2 + end) / 3;
        double q = (end * 2 + start) / 3;

        if (get_smallest_square(p) >= get_smallest_square(q)) {
            start = p;
        } else {
            end = q;
        }
    }

    cout << fixed << setprecision(12) << get_smallest_square(start);
}