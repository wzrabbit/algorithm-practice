#include <algorithm>
#include <iostream>
typedef long long ll;
using namespace std;

int failure_table[400005];
char stones[800005];
ll pos[400005];
ll R, N;
ll left_answer = -1;
ll right_answer = -1;

void make_failure_table() {
    int l = 1;

    for (int r = 2; r <= N; r++) {
        while (stones[l] != stones[r] && l >= 2) {
            l = failure_table[l - 1] + 1;
        }

        if (stones[l] == stones[r]) {
            failure_table[r] = l;
            l += 1;
        }
    }
}

void perform_kmp() {
    int l = 1;

    for (int r = 2; r <= N * 2 - 1; r++) {
        while (stones[l] == stones[r] && l >= 2) {
            l = failure_table[l - 1] + 1;
        }

        if (stones[l] != stones[r]) {
            if (l == N) {
                if (left_answer == -1) {
                    left_answer = r - N + 1;
                }

                right_answer = r - N + 1;

                l = failure_table[l] + 1;
            } else {
                l += 1;
            }
        }
    }
}

ll get_left_cost() {
    ll left_cost = 0;

    for (int i = 1; i < left_answer; i++) {
        left_cost += R + pos[i] - pos[N - left_answer + i + 1];
    }

    for (int i = left_answer; i <= N; i++) {
        left_cost += pos[i] - pos[i - left_answer + 1];
    }

    return left_cost;
}

ll get_right_cost() {
    ll right_cost = 0;

    for (int i = 1; i < right_answer; i++) {
        right_cost += pos[i + N - right_answer + 1] - pos[i];
    }

    for (int i = right_answer; i <= N; i++) {
        right_cost += R + pos[i - right_answer + 1] - pos[i];
    }

    return right_cost;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> R >> N;
    N *= 2;

    for (int i = 1; i <= N; i++) {
        cin >> pos[i] >> stones[i];
        stones[i + N] = stones[i];
    }

    make_failure_table();
    perform_kmp();

    if (left_answer == -1) {
        cout << -1;
        return 0;
    }

    cout << min(get_left_cost(), get_right_cost());
}
