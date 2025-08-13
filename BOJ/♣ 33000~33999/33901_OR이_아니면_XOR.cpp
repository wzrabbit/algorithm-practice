#include <iostream>
typedef long long ll;
using namespace std;

int arr[1000001];
int counts[200001];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N, M, K;
    cin >> N >> M >> K;

    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
    }

    ll answer = 0;

    for (int i = 1; i <= N; i++) {
        if (i > M + 1) {
            counts[arr[i - M - 1]] -= 1;
        }

        int target = arr[i] ^ K;
        answer += counts[target];

        counts[arr[i]] += 1;
    }

    cout << answer;
}
