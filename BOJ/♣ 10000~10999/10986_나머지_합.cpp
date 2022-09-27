#include <algorithm>
#include <iostream>
typedef long long ll;
using namespace std;

ll mod[1000];
ll sum = 0;
ll answer = 0;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N, M;
    cin >> N >> M;
    mod[0]++;

    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;

        sum = (sum + x) % M;
        mod[sum]++;
    }

    for (int i = 0; i < M; i++)
        answer += mod[i] * (mod[i] - 1) / 2;

    cout << answer;
}