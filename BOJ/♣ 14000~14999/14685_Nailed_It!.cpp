#include <iostream>
using namespace std;

int heights[2001];
int lengths[4001];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N;
    cin >> N;

    for (int i = 1; i <= N; i++) {
        int cur;
        cin >> cur;
        heights[cur] += 1;
    }

    for (int i = 1; i <= 2000; i++) {
        for (int j = i; j <= 2000; j++) {
            if (i == j) {
                lengths[i + j] += heights[i] / 2;
            } else {
                lengths[i + j] += min(heights[i], heights[j]);
            }
        }
    }

    int max_length = 0;
    int answer_count = 0;

    for (int i = 2; i <= 4000; i++) {
        if (lengths[i] >= max_length) {
            answer_count += 1;
        }

        if (lengths[i] > max_length) {
            max_length = lengths[i];
            answer_count = 1;
        }
    }

    cout << max_length << ' ' << answer_count;
}
