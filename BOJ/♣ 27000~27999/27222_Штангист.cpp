#include <iostream>
using namespace std;

bool is_exercise[1001];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N;
    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> is_exercise[i];
    }

    int answer = 0;

    for (int i = 1; i <= N; i++) {
        int before, after;
        cin >> before >> after;

        if (is_exercise[i]) {
            answer += max(0, after - before);
        }
    }

    cout << answer;
}
