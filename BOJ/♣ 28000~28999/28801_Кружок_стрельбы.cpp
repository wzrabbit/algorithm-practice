#include <iostream>
#define INF 1'000'000'001
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N;
    cin >> N;

    int pos = INF;
    int answer = 1;

    for (int i = 1; i <= N; i++) {
        int x, a, b;
        cin >> x >> a >> b;

        if (x > pos) {
            answer += 1;
        }

        pos = x + a * b;
    }

    cout << answer;
}