#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>
#define MOD 1'000'000'007
typedef long long ll;
using namespace std;

struct Point {
    int x, y;
};

bool operator<(const Point& a, const Point& b) {
    if (abs(a.x) != abs(b.x)) {
        return abs(a.x) < abs(b.x);
    }

    return abs(a.y) < abs(b.y);
}

map<string, vector<Point>> point_map;
Point points[300001];

int get_quad(int x, int y) {
    if (x > 0 && y > 0) {
        return 1;
    }

    if (x < 0 && y > 0) {
        return 2;
    }

    if (x < 0 && y < 0) {
        return 3;
    }

    if (x > 0 && y < 0) {
        return 4;
    }

    if (x == 0) {
        if (y > 0) {
            return 5;
        } else {
            return 6;
        }
    } else {
        if (x > 0) {
            return 7;
        } else {
            return 8;
        }
    }
}

int get_gcd(int x, int y) {
    if (x % y == 0) {
        return y;
    }

    return get_gcd(y, x % y);
}

string make_key(int x, int y) {
    int quad = get_quad(x, y);

    if (quad >= 5) {
        return to_string(quad);
    }

    int gcd = get_gcd(abs(x), abs(y));
    x /= gcd;
    y /= gcd;

    if (x < 0) {
        x *= -1;
        y *= -1;
    }

    return to_string(quad) + ":" + to_string(x) + "/" + to_string(y);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N, Q;
    cin >> N >> Q;

    for (int i = 1; i <= N; i++) {
        int x, y;
        cin >> x >> y;

        points[i] = {x, y};
    }

    sort(points + 1, points + N + 1);

    for (int i = 1; i <= N; i++) {
        int x = points[i].x;
        int y = points[i].y;

        string cur_key = make_key(x, y);

        if (point_map.find(cur_key) == point_map.end()) {
            point_map[cur_key] = vector<Point>();
        }

        point_map[cur_key].push_back({x, y});
    }

    int answer = 0;

    while (Q--) {
        int x, y;
        cin >> x >> y;

        string cur_key = make_key(x, y);
        vector<Point>& vec = point_map[cur_key];

        int start = 0;
        int end = int(vec.size()) - 1;
        int mid;
        bool should_check_y = cur_key == "5" || cur_key == "6";

        while (start <= end) {
            mid = (start + end) / 2;

            bool ok = (should_check_y) ? abs(y) >= abs(vec[mid].y) : abs(x) >= abs(vec[mid].x);

            if (ok) {
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }

        answer = max(answer, end + 1);
    }

    cout << answer;
}
