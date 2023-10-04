#include <iostream>
using namespace std;

int get_gcd(int a, int b) {
    if (a % b == 0) return b;
    return get_gcd(b, a % b);
}

int arr[100001];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N;
    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
    }

    int gcd = arr[2] - arr[1];

    for (int i = 3; i <= N; i++) {
        gcd = get_gcd(gcd, arr[i] - arr[i - 1]);
    }

    cout << (arr[N] - arr[1]) / gcd - N + 1;
}