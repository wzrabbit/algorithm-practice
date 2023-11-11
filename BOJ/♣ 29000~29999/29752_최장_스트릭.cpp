#include <algorithm>
#include <iostream>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N;
    cin >> N;

    int cur_streak = 0;
    int best_streak = 0;

    for (int i = 1; i <= N; i++) {
        int streak;
        cin >> streak;

        if (streak == 0) {
            cur_streak = 0;
            continue;
        }

        cur_streak += 1;
        best_streak = max(best_streak, cur_streak);
    }

    cout << best_streak;
}