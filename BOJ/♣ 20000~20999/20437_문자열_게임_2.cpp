#include <iostream>
#include <vector>
#define INF 12345
using namespace std;

vector<int> occur[26];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int T;
    cin >> T;

    while (T--) {
        for (int i = 0; i < 26; i++) {
            occur[i].clear();
        }

        string S;
        int K;
        cin >> S >> K;

        for (size_t i = 0; i < S.size(); i++) {
            occur[S[i] - 'a'].push_back(i);
        }

        int max_len = 0;
        int min_len = INF;

        for (int i = 0; i < 26; i++) {
            if (int(occur[i].size()) < K) {
                continue;
            }

            for (int j = 0; j < int(occur[i].size()) - K + 1; j++) {
                int cur_len = occur[i][j + K - 1] - occur[i][j] + 1;
                max_len = max(cur_len, max_len);
                min_len = min(cur_len, min_len);
            }
        }

        if (min_len == INF || max_len == 0) {
            cout << -1;
        } else {
            cout << min_len << ' ' << max_len;
        }

        cout << '\n';
    }
}
