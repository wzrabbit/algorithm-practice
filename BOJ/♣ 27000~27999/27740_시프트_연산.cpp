#include <algorithm>
#include <iostream>
#define INF 999999
using namespace std;

int arr[300002];
int left_need[300002];
int right_need[300002];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N;
    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
    }

    for (int i = 1; i <= N; i++) {
        left_need[i] = left_need[i - 1];
        if (arr[i] == 1) left_need[i] = i;
    }

    for (int i = N; i >= 1; i--) {
        right_need[i] = right_need[i + 1];
        if (arr[i] == 1) right_need[i] = N - i + 1;
    }

    int best = INF;
    int best_index = -1;

    for (int i = 0; i <= N; i++) {
        int cur = left_need[i] + right_need[i + 1] + min(left_need[i], right_need[i + 1]);

        if (cur < best) {
            best = cur;
            best_index = i;
        }
    }

    cout << best << '\n';

    int left = left_need[best_index];
    int right = right_need[best_index + 1];
    int minimum = min(left, right);

    if (left > right) {
        cout << string(right, 'R') << string(left + minimum, 'L');
    } else {
        cout << string(left, 'L') << string(right + minimum, 'R');
    }
}