#include <iostream>
using namespace std;

int dp[1001][1001][201];
int pizza[1001];
int N;

int top_down(int start, int size, int diff) {
    if (size == 0) {
        return 0;
    }

    int &cur = dp[start][size][diff];

    if (cur != -1) {
        return cur;
    }

    if (size == N) {
        for (int i = 1; i <= N; i++) {
            int prev_pizza_index = (i == 1) ? N : i - 1;
            cur =
                max(cur, top_down(i, size - 1, diff + pizza[prev_pizza_index]) +
                             pizza[prev_pizza_index]);
        }

        return cur;
    }

    int left_pizza = pizza[start];
    int right_pizza = pizza[(start + size - 2) % N + 1];

    if (diff > 100) {
        cur = min(top_down(start % N + 1, size - 1, diff - left_pizza),
                  top_down(start, size - 1, diff - right_pizza));
    } else {
        cur = cur = max(
            top_down(start % N + 1, size - 1, diff + left_pizza) + left_pizza,
            top_down(start, size - 1, diff + right_pizza) + right_pizza);
    }
    return cur;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> pizza[i];
    }

    fill(&dp[0][0][0], &dp[1000][1000][201], -1);

    cout << top_down(1, N, 100);
}
