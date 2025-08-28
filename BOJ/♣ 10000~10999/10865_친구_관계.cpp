#include <iostream>
using namespace std;

int friends[100001];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N, M;
    cin >> N >> M;

    for (int i = 1; i <= M * 2; i++) {
        int cur;
        cin >> cur;
        friends[cur] += 1;
    }

    for (int i = 1; i <= N; i++) {
        cout << friends[i] << '\n';
    }
}
