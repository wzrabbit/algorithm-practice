#include <algorithm>
#include <iostream>
using namespace std;

bool is_appeared[10001];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N, K;
    cin >> N >> K;

    int answer = 1;
    int appear_count = 0;

    for (int i = 1; i <= N; i++) {
        int cur;
        cin >> cur;

        if (!is_appeared[cur]) {
            is_appeared[cur] = true;
            appear_count += 1;
        }

        if (appear_count == K) {
            answer += 1;
            fill(is_appeared + 1, is_appeared + K + 1, false);
            appear_count = 0;
        }
    }

    cout << answer;
}
