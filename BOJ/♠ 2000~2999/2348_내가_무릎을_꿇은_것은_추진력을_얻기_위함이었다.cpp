#include <algorithm>
#include <iostream>
#include <string>
#define INF 2'100'000'000
using namespace std;

/**
 * 각 수가 9자리 수를 넘을 수 없다는 것, 첫 번째 수는 무조건 수열의 시작 부분에 걸쳐있다는 점을 고려하면
 * 첫 번째 수가 차지하는 자릿수와 두 번째 수가 차지하는 자릿수를 정하면 답이 정해짐을 알 수 있습니다
 *
 * 두 수가 정해지면 등차 d가 고정되므로, 세 번째 수부터는 직접 자릿수를 한 칸씩 늘려보면서 수를 뒤에 이을 수 있는지를 판별하면 되며,
 * 새로운 수를 이을 때 등차로 이을 수 있는 경우와 등비로 이을 수 있는 경우가 항상 겹치지 않음을 관찰하면
 * 새로운 수로 등차수열을 이루는 경우 등차로 수열이 이어진 것으로 보고 새로운 수를 찾으면 되며,
 * 등비수열을 이루는 경우에는 해당 값을 마지막 값으로 보고 끝까지 순회를 한 후 등비를 이루는지를 판별하면 됩니다.
 */

string S;
int N;

int judge_score(int first, int second, int start_index) {
    if (start_index == N) {
        
    }
    
    int d = second - first;
    int previous = second;
    int cur = 0;
    bool is_last_num = false;

    for (int i = start_index; i < N; i++) {
        if (cur == 0 && S[i] == '0') {
            return INF;
        }

        cur *= 10;
        cur += S[i] - '0';

        if (cur == previous + d) {
            previous = cur;
            cur = 0;
            continue;
        }

        if (cur >= 100'000'000 && cur <= 999'999'999 && i != N - 1) {
            return INF;
        }
    }

    if (cur % previous == 0 && cur / previous >= 2) {
        return cur / previous;
    }

    return INF;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> S;
    N = (int)S.size();

    int best_score = INF;

    for (int i = 0; i < min(N - 1, 9); i++) {
        for (int j = i + 1; j < min(N, i + 10); j++) {
            if (S[i + 1] == '0') {
                continue;
            }

            int first = 0;
            int second = 0;

            for (int k = 0; k <= i; k++) {
                first *= 10;
                first += S[k] - '0';
            }

            for (int k = i + 1; k <= j; k++) {
                second *= 10;
                second += S[k] - '0';
            }

            if (first >= second) {
                continue;
            }

            best_score = min(best_score, judge_score(first, second, j + 1));
        }
    }

    if (best_score == INF) {
        cout << 0;
    } else {
        cout << best_score;
    }
}
