#include <iostream>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N;
    cin >> N;

    int prev;
    cin >> prev;

    int answer = 1;

    for (int i = 1; i <= N - 1; i++) {
        int cur;
        cin >> cur;

        if (prev % 2 != cur % 2) {
            answer += 1;
        }

        prev = cur;
    }

    cout << answer;
}