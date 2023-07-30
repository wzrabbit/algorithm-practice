#include <algorithm>
#include <iostream>
using namespace std;

int main() {
    int N, P;
    cin >> N >> P;

    int moves = min(P, N - P + 1) - 2 + N;

    for (int i = 1; i <= N; i++) {
        int cur;
        cin >> cur;

        moves += cur;
    }

    cout << moves;
}