#include <iostream>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        int answer = 0;

        for (int j = 0; j < N; j++) {
            int cur;
            cin >> cur;
            answer |= cur;
        }

        cout << answer << ' ';
    }
}