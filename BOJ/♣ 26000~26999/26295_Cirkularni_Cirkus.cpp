#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

struct Query {
    int n;
    char s;
};

vector<Query> query;
char answer[26];
bool appeared[26];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N, M;
    cin >> N >> M;

    for (int i = 0; i < M; i++) {
        int x;
        char s;
        cin >> x >> s;

        query.push_back({x, s});
    }

    for (int i = 0; i < N; i++) {
        answer[i] = '?';
    }

    int index = 0;
    bool valid = true;

    for (int i = M - 1; i >= 0; i--) {
        if (answer[index] != '?' && answer[index] != query[i].s) {
            valid = false;
            break;
        }

        answer[index] = query[i].s;
        index = (index + query[i].n) % N;
    }

    for (int i = 0; i < N; i++) {
        if (answer[i] != '?' && appeared[answer[i] - 'A']) {
            valid = false;
            break;
        }

        appeared[answer[i] - 'A'] = true;
    }

    if (valid) {
        for (int i = 0; i < N; i++) {
            cout << answer[i];
        }
    } else {
        cout << '!';
    }
}