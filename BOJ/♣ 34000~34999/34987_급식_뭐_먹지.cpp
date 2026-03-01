#include <iostream>
using namespace std;

int imos[1000002];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N, M;
    cin >> N >> M;

    for (int i = 1; i <= N; i++) {
        int a, b;
        cin >> a >> b;

        int l = a;
        int r = M - b;

        if (l <= r) {
            imos[l] += 1;
            imos[r + 1] -= 1;
        }
    }

    for (int i = 1; i <= M; i++) {
        imos[i] += imos[i - 1];
    }

    int answer = 0;

    for (int i = 0; i <= M; i++) {
        answer = max(answer, imos[i]);
    }

    cout << answer;
}
