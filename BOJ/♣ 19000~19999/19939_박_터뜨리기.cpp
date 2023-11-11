#include <iostream>
typedef long long ll;
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;

    int sum = (K + 1) * K / 2;

    if (sum > N) {
        cout << -1;
    } else if ((N - sum) % K == 0) {
        cout << K - 1;
    } else {
        cout << K;
    }
}
