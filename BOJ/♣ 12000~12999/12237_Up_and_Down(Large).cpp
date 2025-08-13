#include <algorithm>
#include <iostream>
#define INF 1'000'000'001
using namespace std;

int arr[1001];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int T;
    cin >> T;

    for (int t = 1; t <= T; t++) {
        int N;
        cin >> N;

        for (int i = 1; i <= N; i++) {
            cin >> arr[i];
        }

        int answer = 0;

        for (int i = 1; i <= N; i++) {
            int min_value = INF;
            int min_index;

            for (int j = 1; j <= N; j++) {
                if (arr[j] < min_value) {
                    min_value = arr[j];
                    min_index = j;
                }
            }

            int left_cost = 0;
            int right_cost = 0;

            for (int j = min_index - 1; j >= 1; j--) {
                if (arr[j] != INF) left_cost += 1;
            }

            for (int j = min_index + 1; j <= N; j++) {
                if (arr[j] != INF) right_cost += 1;
            }

            answer += min(left_cost, right_cost);
            arr[min_index] = INF;
        }

        cout << "Case #" << t << ": " << answer << '\n';
    }
}
