#include <iostream>
using namespace std;

int cards[1000002];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N;
    cin >> N;

    bool success = true;

    for (int i = 1; i <= 1000000; i++) {
        cin >> cards[i];
    }

    for (int i = 1; i <= N; i++) {
        if (cards[i] == 0) {
            for (int j = 1; j <= 3; j++) {
                if (cards[i - 1] != j && cards[i + 1] != j) {
                    cards[i] = j;
                    break;
                }
            }
        } else {
            if (cards[i] == cards[i + 1]) {
                success = false;
                break;
            }
        }
    }

    if (success) {
        for (int i = 1; i <= N; i++) {
            cout << cards[i] << ' ';
        }
    } else {
        cout << -1;
    }
}