#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;

    int score = 0;
    int no_opinion = 0;

    for (int i = 1; i <= N; i++) {
        int cur;
        cin >> cur;

        score += cur;

        if (cur == 0) {
            no_opinion += 1;
        }
    }

    if (no_opinion > (N - 1) / 2) {
        cout << "INVALID";
        return 0;
    }

    if (score > 0) {
        cout << "APPROVED";
    } else {
        cout << "REJECTED";
    }
}