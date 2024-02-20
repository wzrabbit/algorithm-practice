#include <iostream>
using namespace std;

int arr[100001];
int result[100001];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N, M;
    cin >> N >> M;

    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
    }

    for (int i = 1; i <= M; i++) {
        int cur;
        cin >> cur;

        result[cur] = arr[cur];
    }

    for (int i = 1; i <= N; i++) {
        if (result[i] != 0) {
            continue;
        }

        for (int j = 1; j <= 4; j++) {
            if (j != result[i - 1] && j != arr[i] && j != result[i + 1]) {
                result[i] = j;
                break;
            }
        }
    }

    for (int i = 1; i <= N; i++) {
        cout << result[i] << ' ';
    }
}