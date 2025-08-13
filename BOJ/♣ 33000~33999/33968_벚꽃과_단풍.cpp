#include <algorithm>
#include <iostream>
#define INF 987'654
using namespace std;

int B_prefix[100002];
char S[100002];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N;
    cin >> N;

    cin >> (S + 1);

    for (int i = 1; i <= N; i++) {
        B_prefix[i] = B_prefix[i - 1] + (S[i] == 'B' ? 1 : 0);
    }

    int answer = INF;

    for (int i = 0; i <= N; i++) {
        answer = min(answer, i - B_prefix[i] + B_prefix[N] - B_prefix[i]);
    }

    cout << answer;
}
