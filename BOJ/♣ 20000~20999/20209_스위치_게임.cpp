#include <iostream>
#include <queue>
#include <set>
#include <string>
#include <vector>
using namespace std;

struct State {
    string s;
    int d;
};

set<string> visited;
vector<int> switches[8];
int N, K;

int get_answer(string start) {
    visited.insert(start);
    queue<State> q;
    q.push({start, 0});

    while (!q.empty()) {
        State cur = q.front();
        q.pop();

        bool is_all_same = true;

        for (int i = 1; i < N; i++) {
            if (cur.s[i] != cur.s[0]) {
                is_all_same = false;
                break;
            }
        }

        if (is_all_same) {
            return cur.d;
        }

        for (int i = 0; i < K; i++) {
            string state = cur.s;

            for (size_t j = 0; j < switches[i].size(); j++) {
                state[switches[i][j]] =
                    (state[switches[i][j]] - '0' + i + 1) % 5 + '0';
            }

            if (visited.find(state) == visited.end()) {
                visited.insert(state);
                q.push({state, cur.d + 1});
            }
        }
    }

    return -1;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> N >> K;

    string start = "";

    for (int i = 0; i < N; i++) {
        char cur;
        cin >> cur;
        start += cur;
    }

    for (int i = 0; i < K; i++) {
        int repeat;
        cin >> repeat;

        for (int j = 0; j < repeat; j++) {
            int cur;
            cin >> cur;

            switches[i].push_back(cur - 1);
        }
    }

    cout << get_answer(start);
}
