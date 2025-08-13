#include <algorithm>
#include <iostream>
#define INF 100'000
typedef long long ll;
using namespace std;

struct Rectangle {
    ll x1, y1, x2, y2;
};

Rectangle rectangles[10];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> rectangles[i].x1 >> rectangles[i].y1 >> rectangles[i].x2 >>
            rectangles[i].y2;
    }

    ll answer = 0;

    for (int i = 1; i < (1 << N); i++) {
        ll bit_count = 0;
        ll min_x = -INF;
        ll min_y = -INF;
        ll max_x = INF;
        ll max_y = INF;

        for (int j = 0; j < N; j++) {
            if (i & (1 << j)) {
                bit_count += 1;
                min_x = max(rectangles[j].x1, min_x);
                max_x = min(rectangles[j].x2, max_x);
                min_y = max(rectangles[j].y2, min_y);
                max_y = min(rectangles[j].y1, max_y);
            }
        }

        ll result_area = max(0ll, max_x - min_x) * max(0ll, max_y - min_y);

        if (bit_count % 2 == 1) {
            answer += result_area;
        } else {
            answer -= result_area;
        }
    }

    cout << answer;
}
