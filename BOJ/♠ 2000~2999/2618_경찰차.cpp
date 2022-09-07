#include <algorithm>
#include <initializer_list>
#include <iostream>
#include <vector>
#define INF 2000001
using namespace std;

struct loc {
    int r, c;
};

int S, N;
int dp[1001][1001];       // dp[경찰차 1이 마지막으로 해결한 사건 번호][경찰차 2 "] 이후 움직여야 하는 최소 거리
int history[1001][1001];  // dp[][] 이후 움직여야 하는 경찰차
vector<loc> location;

int get_dist(int before, int after, int no) {
    if (before == 0) {
        if (no == 1) {
            return abs(location[after].r - 1) +
                   abs(location[after].c - 1);
        } else {
            return abs(location[after].r - S) +
                   abs(location[after].c - S);
        }
    }

    return abs(location[after].r - location[before].r) +
           abs(location[after].c - location[before].c);
}

int top_down(int A, int B) {
    int &cur = dp[A][B];
    int &hist = history[A][B];

    if (cur != -1) return cur;
    if (A == N || B == N) return 0;

    int next = max(A, B) + 1;
    int calc1 = top_down(next, B) + get_dist(A, next, 1);
    int calc2 = top_down(A, next) + get_dist(B, next, 2);

    if (calc1 > calc2) {
        cur = calc2;
        hist = 2;
    } else {
        cur = calc1;
        hist = 1;
    }

    return cur;
}

void print_history(int A, int B) {
    int cur = history[A][B];
    int next = max(A, B) + 1;

    cout << history[A][B] << '\n';

    if (A < N - 1 && B < N - 1) {
        if (cur == 1)
            print_history(next, B);
        else
            print_history(A, next);
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> S >> N;
    location.resize(N + 1);
    fill(&dp[0][0], &dp[N][N + 1], -1);

    for (int i = 1; i <= N; i++) {
        int r, c;
        cin >> r >> c;

        location[i] = {r, c};
    }

    cout << top_down(0, 0) << '\n';
    print_history(0, 0);
}