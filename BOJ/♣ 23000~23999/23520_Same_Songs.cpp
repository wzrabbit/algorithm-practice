#include <iostream>
#include <vector>
using namespace std;

int arr[51];
int dp[51];
int history[51];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N;
    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
    }

    for (int i = 2; i <= N; i++) {
        for (int j = 1; j <= i - 1; j++) {
            int cur_repeats = dp[j] + ((arr[j] == arr[i]) ? 1 : 0);

            if (cur_repeats >= dp[i]) {
                dp[i] = cur_repeats;
                history[i] = j;
            }
        }
    }

    int best_index = 0;
    int best_repeats = 0;

    for (int i = 1; i <= N; i++) {
        if (dp[i] >= best_repeats) {
            best_index = i;
            best_repeats = dp[i];
        }
    }

    int pointer = best_index;
    vector<int> answer;

    do {
        answer.push_back(arr[pointer]);
        pointer = history[pointer];
    } while (pointer != 0);

    cout << answer.size() << ' ' << dp[best_index] << '\n';

    for (int i = (int)answer.size() - 1; i >= 0; i--) {
        cout << answer[i] << ' ';
    }

    cout << '\n';
}