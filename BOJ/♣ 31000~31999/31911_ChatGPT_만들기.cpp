#include <algorithm>
#include <iostream>
#include <string>
typedef long long ll;
using namespace std;

ll db[151][151];
char next_char[151];
ll visited[151];
ll N, K, M;
string result = " ";

void traverse() {
    char cur = '[';
    ll cur_time = 0;
    bool ended = false;

    while (visited[cur] == 0) {
        cur_time += 1;
        visited[cur] = cur_time;
        result += cur;

        if (cur == ']') {
            ended = true;
            break;
        }

        cur = next_char[cur];
    }

    if (ended) {
        for (ll i = K; i <= K + M - 1; i++) {
            if (i <= cur_time) {
                cout << result[i];
            } else {
                cout << '.';
            }
        }

        return;
    }

    ll loop_size = cur_time - visited[cur] + 1;
    ll loop_start = visited[cur];
    ll loop_end = cur_time - 1;

    if (K <= cur_time) {
        char cur = result[K];

        while (M--) {
            cout << cur;
            cur = next_char[cur];
        }

        return;
    }

    cur = result[loop_start + (K - loop_start) % loop_size];

    while (M--) {
        cout << cur;
        cur = next_char[cur];
    }

    return;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> N >> K >> M;

    for (int i = 1; i <= N; i++) {
        string S;
        cin >> S;

        for (size_t i = 1; i < S.size(); i++) {
            char previous = S[i - 1];
            char current = S[i];
            db[previous][current] += 1;
        }
    }

    for (int i = 1; i <= 150; i++) {
        char best_char = '@';
        int best_count = 0;

        for (int j = 1; j <= 150; j++) {
            if (db[i][j] > best_count) {
                best_char = j;
                best_count = db[i][j];
            }
        }

        next_char[i] = best_char;
    }

    traverse();
}
