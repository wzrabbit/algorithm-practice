#include <iostream>
#define MOD 1'000'000'007
using namespace std;

int main() {
    int N;
    cin >> N;

    int a = 1;
    int b = 1;
    int c = 2;

    for (int i = 4; i <= N; i++) {
        a = b;
        b = c;
        c = (a + b) % MOD;
    }

    cout << c << ' ' << N - 2;
}
