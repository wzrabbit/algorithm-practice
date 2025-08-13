#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int T;
    cin >> T;

    while (T--) {
        int N;
        string S;
        cin >> N >> S;

        int odd = 1;
        int even = 2;
        bool is_top_turn = true;

        vector<pair<int, int>> answer;

        for (size_t i = 0; i < S.size(); i++) {
            if (S[i] == 'O') {
                answer.push_back(make_pair(odd, even));
                odd += 2;
                even += 2;
                continue;
            }

            if (is_top_turn) {
                answer.push_back(make_pair(odd, odd + 2));
                odd += 4;
            } else {
                answer.push_back(make_pair(even, even + 2));
                even += 4;
            }

            is_top_turn = !is_top_turn;
        }

        if (odd != N * 2 + 1 || odd + 1 != even) {
            cout << "NO\n";
            continue;
        }

        cout << "YES\n";

        for (pair<int, int> cur : answer) {
            cout << cur.first << ' ' << cur.second << '\n';
        }
    }
}
