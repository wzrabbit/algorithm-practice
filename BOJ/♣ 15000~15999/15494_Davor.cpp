#include <iostream>
using namespace std;

void solve(int N) {
    for (int X = 100; X >= 1; X--) {
        for (int K = 1; K <= 145600; K++) {
            int calc = X * 364 + K * 21 * 52;
            if (calc == N) {
                cout << X << '\n'
                     << K;
                return;
            }
        }
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N;
    cin >> N;
    solve(N);
}