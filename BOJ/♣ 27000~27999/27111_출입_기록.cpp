#include <iostream>
using namespace std;

int state[200001];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N;
    cin >> N;

    int wrong_count = 0;

    for (int i = 1; i <= N; i++) {
        int num, history;
        cin >> num >> history;

        if (state[num] == history) {
            wrong_count += 1;
        }

        state[num] = history;
    }

    for (int i = 1; i <= 200000; i++) {
        if (state[i] == 1) {
            wrong_count += 1;
        }
    }

    cout << wrong_count;
}