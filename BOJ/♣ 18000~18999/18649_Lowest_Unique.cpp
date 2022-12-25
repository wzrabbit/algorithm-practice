#include <iostream>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N, A, T, x;
    cin >> N >> A >> T;

    while (T--) {
        for (int i = 1; i <= A; i++) cout << i << ' ';
        cout << endl;
        for (int i = 1; i <= N - A; i++) cin >> x;
    }
}