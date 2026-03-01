#include <iostream>
using namespace std;

int arr[1000];
bool is_used[1001];
int answer[1001];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N;
    cin >> N;

    for (int i = 1; i <= N - 1; i++) {
        cin >> arr[i];
    }

    for (int i = 1; i <= N; i++) {
        fill(is_used + 1, is_used + N + 1, false);
        answer[1] = i;
        is_used[i] = true;
        bool success = true;

        for (int j = 2; j <= N; j++) {
            int cur = arr[j - 1] - answer[j - 1];
            answer[j] = cur;

            if (cur < 1 || cur > N || is_used[cur]) {
                success = false;
                break;
            }
            is_used[cur] = true;
        }

        if (success) {
            break;
        }
    }

    for (int i = 1; i <= N; i++) {
        cout << answer[i] << ' ';
    }
}
