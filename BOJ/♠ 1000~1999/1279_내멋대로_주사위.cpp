#include <algorithm>
#include <iostream>
#define MOD 1000000007
typedef long long ll;
using namespace std;

int P[16][7];

int conv(int num) {
    num += 16;
    return num % 16;
}

int main() {
    int N;
    cin >> N;
    N *= 6;
    ll dice = 0;

    P[1][1] = 1;

    for (int n = 2; n <= N; n++) {
        for (int k = 1; k <= min(n, 6); k++) {
            P[conv(n)][k] = (P[conv(n - 1)][k - 1] + P[conv(n - k)][k]) % MOD;
        }

        if (n >= 15)
            dice = (dice + P[conv(n - 15)][6]) % MOD;  // Q(N, K)
    }

    cout << dice * 30 % MOD;  // 모든 눈이 다른 주사위 경우의 수 = 30
}