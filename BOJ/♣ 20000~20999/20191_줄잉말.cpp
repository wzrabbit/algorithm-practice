#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> positions[26];

int get_next_index(char letter, int cur_index) {
    if (positions[letter - 'a'].size() == 0) {
        return -2;
    }

    auto upper = upper_bound(positions[letter - 'a'].begin(), positions[letter - 'a'].end(), cur_index);

    if (upper == positions[letter - 'a'].end()) {
        return -1;
    }

    return *upper;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    string S, T;
    cin >> S >> T;

    for (size_t i = 0; i < T.size(); i++) {
        positions[T[i] - 'a'].push_back(i);
    }

    int answer = 1;
    int s_index = 0;
    int t_index = -1;

    while (s_index < S.size()) {
        int next_index = get_next_index(S[s_index], t_index);

        if (next_index == -2) {
            cout << -1;
            return 0;
        }

        if (next_index == -1) {
            t_index = -1;
            answer += 1;
            continue;
        }

        s_index += 1;
        t_index = next_index;
    }

    cout << answer;
}
