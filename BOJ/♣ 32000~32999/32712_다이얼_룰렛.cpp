#include <algorithm>
#include <iostream>
typedef long long ll;
using namespace std;

ll scores[200001];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll N, K;
    cin >> N >> K;

    for (int i = 1; i <= N; i++) {
        cin >> scores[i];
    }

    ll answer = 0;
    ll traverse_score = 0;

    for (int i = 1; i <= min(K, N); i++) {
        traverse_score += scores[i];
        answer = max(answer, traverse_score + (K - i) * scores[i]);
    }

    reverse(scores + 1, scores + N + 1);

    traverse_score = 0;

    for (int i = 1; i <= min(K, N); i++) {
        traverse_score += scores[i];
        answer = max(answer, traverse_score + (K - i) * scores[i]);
    }

    cout << answer;
}
