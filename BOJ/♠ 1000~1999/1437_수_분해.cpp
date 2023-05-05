#include <iostream>
#define MOD 10007
using namespace std;

int main() {
    int N;
    cin >> N;

    if (N == 0) {
        cout << 0 << '\n';
        return 0;
    }

    int result = 1;

    while (N >= 2) {
        if (N == 2 || N == 4) {
            result = (result * 2) % MOD;
            N -= 2;
            continue;
        }

        result = (result * 3) % MOD;
        N -= 3;
    }

    cout << result << '\n';
}