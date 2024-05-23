#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

int N, K;
string words[2][10001];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> N >> K;

    for (int i = 1; i <= N; i++) {
        string word;
        cin >> word;

        words[0][i] = word.substr(0, K);
        words[1][i] = word.substr(K, 2 * K);
    }

    for (int i = 1; i <= N; i++) {
        reverse(words[1][i].begin(), words[1][i].end());
    }

    sort(&words[0][1], &words[0][N + 1]);
    sort(&words[1][1], &words[1][N + 1]);

    int answer = 2 * K;

    for (int i = 0; i < 2; i++) {
        for (int j = 2; j <= N; j++) {
            int diff = K;

            for (int k = 0; k < K; k++) {
                if (words[i][j][k] == words[i][j - 1][k]) {
                    diff -= 1;
                } else {
                    break;
                }
            }

            answer += diff;
        }
    }

    cout << answer;
}
