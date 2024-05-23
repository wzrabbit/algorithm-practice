#include <algorithm>
#include <iostream>
#include <vector>
typedef long long ll;
using namespace std;

struct Point {
    ll x, y;
};

Point points[51];

ll ccw(Point a, Point b, Point c) {
    return (b.x - a.x) * (c.y - a.y) - (c.x - a.x) * (b.y - a.y);
}

bool check(Point a, Point b, Point c, Point d) {
    vector<ll> results;
    int pos_count = 0;
    int neg_count = 0;

    results.push_back(ccw(a, b, c));
    results.push_back(ccw(b, c, d));
    results.push_back(ccw(c, d, a));
    results.push_back(ccw(d, a, b));

    for (size_t i = 0; i < 4; i++) {
        if (results[i] > 0) {
            pos_count += 1;
        } else if (results[i] < 0) {
            neg_count += 1;
        }
    }

    return pos_count == 4 || neg_count == 4;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N;
    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> points[i].x >> points[i].y;
    }

    int answer = 0;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            for (int k = 1; k <= N; k++) {
                for (int l = 1; l <= N; l++) {
                    if (i == j || i == k || i == l || j == k || j == l || k == l) {
                        continue;
                    }

                    if (check(points[i], points[j], points[k], points[l])) {
                        answer += 1;
                    }
                }
            }
        }
    }

    answer /= 8;

    cout << answer;
}
