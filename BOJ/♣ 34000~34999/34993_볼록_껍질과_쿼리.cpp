#include <iostream>
using namespace std;

struct Point {
    int x, y;
};

Point answer[101];
Point response[101][4];
int _;

bool is_point_same(Point a, Point b) { return a.x == b.x && a.y == b.y; }

void solve_even(int N) {
    for (int i = 1; i <= N - 2; i += 2) {
        cout << "? " << 3 << ' ' << i << ' ' << i + 1 << ' ' << i + 2 << endl;
        cin >> _ >> response[i][1].x >> response[i][1].y >> response[i][2].x >>
            response[i][2].y >> response[i][3].x >> response[i][3].y;
    }

    cout << "? " << 3 << ' ' << N - 1 << ' ' << N << ' ' << 1 << endl;
    cin >> _ >> response[N - 1][1].x >> response[N - 1][1].y >>
        response[N - 1][2].x >> response[N - 1][2].y >> response[N - 1][3].x >>
        response[N - 1][3].y;

    for (int i = 3; i <= N - 1; i += 2) {
        for (int j = 1; j <= 3; j++) {
            for (int k = 1; k <= 3; k++) {
                if (is_point_same(response[i][j], response[i - 2][k])) {
                    answer[i] = response[i][j];
                }
            }
        }
    }

    for (int i = 1; i <= 3; i++) {
        for (int j = 1; j <= 3; j++) {
            if (is_point_same(response[1][i], response[N - 1][j])) {
                answer[1] = response[1][i];
            }
        }
    }

    for (int i = 2; i <= N; i += 2) {
        bool first_same = false;
        bool third_same = false;

        for (int j = 1; j <= 3; j++) {
            if (!first_same &&
                is_point_same(response[i - 1][j], answer[i - 1])) {
                first_same = true;
                continue;
            }

            if (!third_same &&
                is_point_same(response[i - 1][j],
                              (i + 1 > N ? answer[1] : answer[i + 1]))) {
                third_same = true;
                continue;
            }

            answer[i] = response[i - 1][j];
            break;
        }
    }

    cout << "! ";

    for (int i = 1; i <= N; i++) {
        cout << answer[i].x << ' ' << answer[i].y << ' ';
    }
    cout << endl;
}

void solve_odd(int N) {
    for (int i = 1; i <= N - 2; i += 2) {
        cout << "? " << 3 << ' ' << i << ' ' << i + 1 << ' ' << i + 2 << endl;
        cin >> _ >> response[i][1].x >> response[i][1].y >> response[i][2].x >>
            response[i][2].y >> response[i][3].x >> response[i][3].y;
    }

    cout << "? " << 3 << ' ' << N << ' ' << 1 << ' ' << 5 << endl;
    cin >> _ >> response[N][1].x >> response[N][1].y >> response[N][2].x >>
        response[N][2].y >> response[N][3].x >> response[N][3].y;

    for (int i = 3; i <= N; i += 2) {
        for (int j = 1; j <= 3; j++) {
            for (int k = 1; k <= 3; k++) {
                if (is_point_same(response[i][j], response[i - 2][k])) {
                    answer[i] = response[i][j];
                }
            }
        }
    }

    for (int i = 1; i <= 3; i++) {
        for (int j = 1; j <= 3; j++) {
            if (is_point_same(response[1][i], response[N][j])) {
                answer[1] = response[1][i];
            }
        }
    }

    for (int i = 2; i <= N; i += 2) {
        bool first_same = false;
        bool third_same = false;

        for (int j = 1; j <= 3; j++) {
            if (!first_same &&
                is_point_same(response[i - 1][j], answer[i - 1])) {
                first_same = true;
                continue;
            }

            if (!third_same &&
                is_point_same(response[i - 1][j],
                              (i + 1 > N ? answer[1] : answer[i + 1]))) {
                third_same = true;
                continue;
            }

            answer[i] = response[i - 1][j];
            break;
        }
    }

    cout << "! ";

    for (int i = 1; i <= N; i++) {
        cout << answer[i].x << ' ' << answer[i].y << ' ';
    }
    cout << endl;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N;
    cin >> N;

    if (N % 2 == 0) {
        solve_even(N);
    } else {
        solve_odd(N);
    }
}
