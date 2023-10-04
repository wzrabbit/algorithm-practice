#include <iostream>
using namespace std;

int prefix[100001][4];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N, Q;
    cin >> N >> Q;

    for (int i = 1; i <= N; i++) {
        int cur;
        cin >> cur;

        for (int j = 1; j <= 3; j++) {
            prefix[i][j] += prefix[i - 1][j];
        }

        prefix[i][cur] += 1;
    }

    for (int i = 1; i <= Q; i++) {
        int s, e;
        cin >> s >> e;

        for (int j = 1; j <= 3; j++) {
            cout << prefix[e][j] - prefix[s - 1][j] << ' ';
        }

        cout << '\n';
    }
}