#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#define INF 3'000'000
typedef long long ll;
using namespace std;

struct Point {
    ll x, y;
};

Point points[21];
bool is_selected[21];
int N;
double answer;

void update_answer() {
    ll x = 0;
    ll y = 0;

    for (int i = 1; i <= N; i++) {
        if (is_selected[i]) {
            x += points[i].x;
            y += points[i].y;
        } else {
            x -= points[i].x;
            y -= points[i].y;
        }
    }

    answer = min(answer, sqrt(x * x + y * y));
}

void backtrack(int index, int selected_count) {
    if (selected_count == N / 2) {
        update_answer();
        return;
    }

    for (int i = index; i <= N; i++) {
        is_selected[index] = true;
        backtrack(i + 1, selected_count + 1);
        is_selected[index] = false;
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cout << fixed << setprecision(7);

    int T;
    cin >> T;

    while (T--) {
        cin >> N;

        for (int i = 1; i <= N; i++) {
            cin >> points[i].x >> points[i].y;
        }

        fill(is_selected + 1, is_selected + N + 1, false);
        answer = INF;

        backtrack(1, 0);
        cout << answer << '\n';
    }
}
