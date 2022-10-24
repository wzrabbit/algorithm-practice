#include <algorithm>
#include <iostream>
using namespace std;

int num[2000001];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N, S, x;
    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> x;
        num[x]++;
    }

    cin >> S;
    int l = 1;
    int r = S - 1;
    int cnt = 0;

    while (l < r) {
        cnt += min(num[l], num[r]);
        l++;
        r--;
    }

    cout << cnt;
}