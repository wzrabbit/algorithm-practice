#include <iostream>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N;
    cin >> N;

    int answer = 0;
    int line_count = 1;
    int plus = 1;

    while (line_count < N) {
        line_count += plus;
        plus += 1;
        answer += 1;
    }

    cout << answer << '\n';

    for (int i = 1; i <= answer; i++) {
        cout << -5000 << ' ' << 5001 - i << ' ' << -5000 + i << ' ' << -5000 << '\n';
    }
}
