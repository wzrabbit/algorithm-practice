#include <algorithm>
#include <iostream>
#include <vector>
typedef long long ll;
using namespace std;

int beads[1001];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;

        for (int i = 1; i <= N; i++) {
            int cur;
            cin >> cur;

            beads[i] = beads[i + N] = cur;
        }

        ll best_score = 0;

        for (int i = 1; i <= N; i++) {
            vector<int> selected;
            selected.push_back(beads[i]);
            selected.push_back(beads[i + 1]);
            ll score = beads[i] ^ beads[i + 1];

            for (int j = i + 2; j <= i + N - 2; j++) {
                int ban_score = selected[selected.size() - 2] ^ beads[j];
                int accept_score = (selected[selected.size() - 2] ^ selected[selected.size() - 1]) + (selected[selected.size() - 1] ^ beads[j]);

                if (ban_score > accept_score) {
                    score -= selected[selected.size() - 2] ^ selected[selected.size() - 1];
                    score += selected[selected.size() - 2] ^ beads[j];

                    selected.pop_back();
                    selected.push_back(beads[j]);

                    continue;
                }

                score += selected[selected.size() - 1] ^ beads[j];
                selected.push_back(beads[j]);
            }

            int ban_score = selected[selected.size() - 1] ^ beads[i];
            int accept_score = (selected[selected.size() - 1] ^ beads[i + N - 1]) + (beads[i + N - 1] ^ beads[i]);

            score += max(ban_score, accept_score);
            best_score = max(best_score, score);

            if (accept_score > ban_score) {
                selected.push_back(beads[i + N - 1]);
            }
        }

        cout << best_score << '\n';
    }
}