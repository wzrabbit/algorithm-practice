#include <algorithm>
#include <iostream>
using namespace std;

struct Picture {
    int h, c;
};

bool operator<(const Picture &a, const Picture &b) { return a.h < b.h; }

Picture pictures[300001];
int dp[300001];
int max_possible_indexes[300001];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N, S;
    cin >> N >> S;

    for (int i = 1; i <= N; i++) {
        cin >> pictures[i].h >> pictures[i].c;
    }

    sort(pictures + 1, pictures + N + 1);

    int index = 1;

    for (int i = 1; i <= N; i++) {
        while (pictures[index].h + S <= pictures[i].h) {
            index += 1;
        }

        max_possible_indexes[i] = index - 1;
    }

    for (int i = 1; i <= N; i++) {
        dp[i] = max(dp[i - 1], dp[max_possible_indexes[i]] + pictures[i].c);
    }

    cout << dp[N];
}
