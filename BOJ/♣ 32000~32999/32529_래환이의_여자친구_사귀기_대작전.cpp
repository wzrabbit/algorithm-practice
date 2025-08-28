#include <iostream>
using namespace std;

int arr[100001];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N, M;
    cin >> N >> M;

    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
    }

    int sum = 0;

    for (int i = N; i>=1; i--) {
        sum += arr[i];

        if (sum >= M) {
            cout << i;
            return 0;
        }
    }

    cout << -1;
}
