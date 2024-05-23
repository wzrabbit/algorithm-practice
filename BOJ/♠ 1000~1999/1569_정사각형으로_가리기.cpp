#include <algorithm>
#include <iostream>
#define INF 9999
using namespace std;

struct Point {
    int x, y;
};

Point points[51];
int N;

bool is_valid(int start_x, int start_y, int width) {
    int end_x = start_x + width;
    int end_y = start_y + width;

    for (int i = 1; i <= N; i++) {
        int x = points[i].x;
        int y = points[i].y;

        bool cur_is_valid = ((x == start_x || x == end_x) && y >= start_y && y <= end_y) ||
                            ((y == start_y || y == end_y) && x >= start_x && x <= end_x);

        if (!cur_is_valid) {
            return false;
        }
    }

    return true;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> N;

    int min_x = INF;
    int min_y = INF;
    int max_x = -INF;
    int max_y = -INF;

    for (int i = 1; i <= N; i++) {
        cin >> points[i].x >> points[i].y;
        min_x = min(min_x, points[i].x);
        min_y = min(min_y, points[i].y);
        max_x = max(max_x, points[i].x);
        max_y = max(max_y, points[i].y);
    }

    int x_gap = abs(max_x - min_x);
    int y_gap = abs(max_y - min_y);

    if (x_gap >= y_gap) {
        for (int y = -1000; y <= 1000; y++) {
            if (is_valid(min_x, y, x_gap)) {
                cout << x_gap;
                return 0;
            }
        }
    } else {
        for (int x = -1000; x <= 1000; x++) {
            if (is_valid(x, min_y, y_gap)) {
                cout << y_gap;
                return 0;
            }
        }
    }

    cout << -1;
}
