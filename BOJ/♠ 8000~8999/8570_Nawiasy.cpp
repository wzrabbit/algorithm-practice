#include <iostream>
#include <string>
typedef long long ll;
using namespace std;

ll combo[1000001];

int main() {
    cin.tie(0)->sync_with_stdio();

    int N;
    string S;
    cin >> N >> S;

    int cur_level = 0;
    ll answer = 0;

    for (int i = 0; i < N; i++) {
        if (S[i] == '(') {
            cur_level += 1;
            continue;
        }

        answer += combo[cur_level + 1] * (combo[cur_level + 1] + 1) / 2;
        combo[cur_level + 1] = 0;

        if (cur_level > 0) {
            combo[cur_level] += 1;
            cur_level -= 1;
        }
    }

    for (int i = 1; i <= 1000000; i++) {
        answer += combo[i] * (combo[i] + 1) / 2;
    }

    cout << answer;
}