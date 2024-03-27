#include <algorithm>
#include <iomanip>
#include <iostream>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N;
    cin >> N;

    cout << fixed << setprecision(1);

    if (N >= 30) {
        cout << 15 + 1.5 * (N - 30);
    } else {
        cout << N / 2.0;
    }
}
