#include <iostream>
#include <string>
#include <vector>
using namespace std;

int arr[100001];
int scores[100001];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N, K, R;
    cin >> N >> K >> R;

    int max_score = 0;

    for (int i = 1; i <= R; i++) {
        for (int j = 1; j <= K; j++) {
            cin >> arr[j];
        }

        string result;
        cin >> result;

        if (result == "satisfied") {
            for (int j = 1; j <= K; j++) {
                scores[arr[j]] = -1;
            }
        } else {
            for (int j = 1; j <= K; j++) {
                scores[arr[j]] += 1;
            }
            max_score += 1;
        }
    }

    int candidate_count = 0;

    for (int i = 1; i <= N; i++) {
        if (scores[i] == max_score) {
            candidate_count += 1;
        }
    }

    int answer = 0;

    while (candidate_count > 1) {
        answer += 1;
        candidate_count =
            candidate_count - min(min(N - K, K), candidate_count / 2);
    }

    cout << answer;
}
