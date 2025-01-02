#include <algorithm>
#include <iostream>
#include <queue>
#define INF 1'000'000'000'000
typedef long long ll;
using namespace std;

int arr[400001];
int minus_values[800002];
int minus_count = 0;
int plus_count = 0;
ll best_diff = INF;
ll cur_diff = 0;
int N, K;

void init() {
    for (int i = 4; i <= N + 2; i++) {
        int diff = arr[i] - (i - 2);
        cur_diff += abs(diff);

        if (diff >= 0) {
            plus_count += 1;
            continue;
        }

        minus_values[N + 2 - diff] += 1;
        minus_count += 1;
        continue;
    }

    cur_diff += abs(1 - arr[1]);
    cur_diff += abs(1 - arr[2]);
    cur_diff += abs(1 - arr[3]);
    cur_diff += abs(N - arr[N + 3]);
    cur_diff += abs(N - arr[N + 4]);
    best_diff = cur_diff;
}

void progress(int index) {
    cur_diff -= minus_count;
    cur_diff += plus_count;

    minus_count -= minus_values[index];
    plus_count += minus_values[index] - 1;

    int diff = arr[index] - N;

    if (diff == 0) {
        plus_count += 1;
    } else {
        minus_values[index - diff] += 1;
        minus_count += 1;
    }

    cur_diff -= abs(1 - arr[index - N - 2]);
    cur_diff += abs(N - arr[index + 2]);

    best_diff = min(best_diff, cur_diff);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> N >> K;

    for (int i = 1; i <= K; i++) {
        cin >> arr[i];
    }

    init();

    for (int i = N + 3; i <= K - 2; i++) {
        progress(i);
    }

    cout << best_diff;
}
