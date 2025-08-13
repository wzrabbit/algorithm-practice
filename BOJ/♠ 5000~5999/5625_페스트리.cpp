#include <iostream>
#define INF 1'000'000'000
using namespace std;

int x_prefix[1000001];
int y_prefix[1000001];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N;
    cin >> N;

    for (int i = 1; i <= N; i++) {
        int min_x = INF;
        int max_x = -INF;
        int min_y = INF;
        int max_y = -INF;

        for (int i = 1; i <= 3; i++) {
            int x, y;
            cin >> x >> y;
            min_x = min(x, min_x);
            max_x = max(x, max_x);
            min_y = min(y, min_y);
            max_y = max(y, max_y);
        }

        x_prefix[min_x + 1] += 1;
        x_prefix[max_x] -= 1;
        y_prefix[min_y + 1] += 1;
        y_prefix[max_y] -= 1;
    }

    for (int i = 1; i <= 1000000; i++) {
        x_prefix[i] += x_prefix[i - 1];
        y_prefix[i] += y_prefix[i - 1];
    }

    int Q;
    cin >> Q;

    while (Q--) {
        char axis, _;
        int value;
        cin >> axis >> _ >> value;

        if (axis == 'x') {
            cout << x_prefix[value] << '\n';
        } else {
            cout << y_prefix[value] << '\n';
        }
    }
}
