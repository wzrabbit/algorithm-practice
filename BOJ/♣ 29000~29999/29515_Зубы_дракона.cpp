#include <algorithm>
#include <iostream>
using namespace std;

int teeth_up[1001], teeth_down[1001];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N, limit;
    cin >> N >> limit;

    for (int i = 1; i <= N; i++) {
        cin >> teeth_up[i];
    }

    for (int i = 1; i <= N; i++) {
        cin >> teeth_down[i];
    }

    int answer = N;

    for (int i = -N + 1; i <= N - 1; i++) {
        int max_height = 0;

        for (int j = 1; j <= N; j++) {
            if (j + i < 1 || j + i > N) {
                continue;
            }

            if (teeth_up[j] == 0 || teeth_down[j + i] == 0) {
                continue;
            }

            max_height = max(max_height, teeth_up[j] + teeth_down[j + i]);
        }

        if (max_height <= limit) {
            answer = min(answer, abs(i));
        }
    }

    cout << answer;
}
