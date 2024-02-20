#include <iostream>
using namespace std;

bool is_banned[201][201];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N, B;
    cin >> N >> B;

    for (int i = 1; i <= B; i++) {
        int a, b;
        cin >> a >> b;

        is_banned[a][b] = true;
        is_banned[b][a] = true;
    }

    int possible_count = 0;

    for (int i = 1; i <= N - 2; i++) {
        for (int j = i + 1; j <= N - 1; j++) {
            for (int k = j + 1; k <= N; k++) {
                if (!is_banned[i][j] && !is_banned[i][k] && !is_banned[j][k]) {
                    possible_count += 1;
                }
            }
        }
    }

    cout << possible_count;
}