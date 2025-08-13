#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N, K;
    string S;

    cin >> N >> K >> S;

    int max_delete_count = 0;

    for (int i = 0; i < N - 1; i++) {
        for (int j = i + 1; j < N; j++) {
            if (S[i] != S[j] || S[i] == 'X' || S[j] == 'X') {
                continue;
            }

            max_delete_count = max(max_delete_count, j - i + 1);
        }
    }

    for (int i = 0; i < N - 1; i++) {
        for (int j = i + 1; j < N; j++) {
            for (int k = 0; k < N - 1; k++) {
                for (int l = k + 1; l < N; l++) {
                    if (!(S[i] == S[j] && S[k] == S[l] && S[i] != 'X' &&
                          S[k] != 'X')) {
                        continue;
                    }

                    if (i == k || j == l) {
                        continue;
                    }

                    if (i < k && k < l && l < j) {
                        max_delete_count = max(max_delete_count, j - i + 1);
                        continue;
                    }

                    if (k < i && i < j && j < l) {
                        max_delete_count = max(max_delete_count, l - k + 1);
                        continue;
                    }

                    if (i < j && j < k && k < l) {
                        max_delete_count =
                            max(max_delete_count, j - i + l - k + 2);
                    }

                    if (k < l && l < i && i < j) {
                        max_delete_count =
                            max(max_delete_count, j - i + l - k + 2);
                    }
                }
            }
        }
    }

    cout << N - max_delete_count;
}
