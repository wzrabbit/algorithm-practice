#include <iostream>
#include <set>
#include <vector>
typedef long long ll;
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    set<ll> occupied = {0};
    vector<ll> state = {0};
    ll answer = -1;

    int N;
    cin >> N;

    for (int i = 1; i <= N; i++) {
        ll cur;
        cin >> cur;

        occupied.insert(cur);
    }

    int try_count = 0;

    while (true) {
        vector<ll> next_state;
        try_count += 1;

        for (size_t i = 0; i < state.size(); i++) {
            bool has_left = occupied.find(state[i] * 2) != occupied.end();
            bool has_right = occupied.find(state[i] * 2 + 1) != occupied.end();
            answer += 1;

            if (has_left && has_right) {
                continue;
            }

            if (!has_left) {
                next_state.push_back(state[i] * 2);
            }

            if (!has_right) {
                next_state.push_back(state[i] * 2 + 1);
            }
        }

        if (next_state.size() > 500'000 || try_count >= 62) {
            cout << -1;
            return 0;
        }

        if (next_state.size() == 0) {
            break;
        }

        swap(next_state, state);
    }

    cout << answer;
}
