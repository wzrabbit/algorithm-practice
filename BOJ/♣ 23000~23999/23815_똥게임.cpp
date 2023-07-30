#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

struct Obstacle {
    string left, right;
};

int dp[100001][2];  // dp[r번째 장애물까지 건너고][광고 기회가 c번 남았을 때] = 사람 수의 최댓값
Obstacle obstacle[100001];

int calculate(int number, string &command) {
    if (command[0] == '+') return number + (command[1] - '0');
    if (command[0] == '-') return number - (command[1] - '0');
    if (command[0] == '*') return number * (command[1] - '0');
    return number / (command[1] - '0');
}

int top_down(int stage, int chance) {
    int &cur = dp[stage][chance];

    if (cur != -1) return cur;
    cur = 0;

    // 이번에 광고를 보지 않는다면? (이전 단계 -> 이번 장애물 건넌 후)
    int before = top_down(stage - 1, chance);
    if (before > 0) {
        before = max(
            calculate(before, obstacle[stage].left),
            calculate(before, obstacle[stage].right));
    }

    // 이번에 광고를 건너뛰겠다면? (이전 단계 -> 광고 시청 (기회 1회 감소))
    int before_with_ad = 0;
    if (chance == 0) before_with_ad = top_down(stage - 1, 1);

    cur = max(before, before_with_ad);

    if (cur <= 0) return 0;
    return cur;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);  // FAST_IO 와 동일

    int N;
    cin >> N;

    for (int i = 1; i <= N; i++) {
        string left, right;
        cin >> left >> right;

        obstacle[i] = {left, right};
    }

    fill(&dp[0][0], &dp[N][2], -1);

    // 0번째 장애물까지 건넜으면 사람 수는 1명
    dp[0][1] = 1;

    // N번째 장애물까지 건넜을 때, 광고 찬스가 0회 또는 1회 남았을 때의 경우 중 최적값은?
    int answer = max(top_down(N, 1), top_down(N, 0));

    if (answer > 0) {
        cout << answer;
    } else {
        cout << "ddong game";
    }
}
