#include <algorithm>
#include <iostream>
using namespace std;

int arr[2222222];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N;
    int all_xor = 0;
    int best = 0;
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
        all_xor ^= arr[i];
    }

    best = all_xor;
    for (int i = 0; i < N; i++) {
        best = max(best, all_xor ^ arr[i]);
    }

    cout << best << best;
}