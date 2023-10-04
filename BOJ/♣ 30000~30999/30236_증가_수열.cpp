#include <iostream>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;

        int answer = 0;

        for (int i = 1; i <= N; i++) {
            int cur;
            cin >> cur;

            if (answer + 1 == cur) {
                answer += 2;
            } else {
                answer += 1;
            }
        }

        cout << answer << '\n';
    }
}
