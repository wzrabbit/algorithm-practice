#include <algorithm>
#include <iostream>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int T;
    cin >> T;

    for (int t = 1; t <= T; t++) {
        int N;
        cin >> N;

        int tessa_score = 0;
        int danny_score = 0;

        for (int i = 1; i <= N; i++) {
            int a, b;
            cin >> a >> b;

            if (a > b) {
                if (a - b == 1) {
                    if (b == 1) {
                        danny_score += 6;
                    } else {
                        danny_score += a + b;
                    }
                } else {
                    tessa_score += a;
                }
            } else if (a < b) {
                if (b - a == 1) {
                    if (a == 1) {
                        tessa_score += 6;
                    } else {
                        tessa_score += a + b;
                    }
                } else {
                    danny_score += b;
                }
            }
        }

        cout << "Game " << t << ": "
             << "Tessa " << tessa_score << " Danny " << danny_score << '\n';
    }
}