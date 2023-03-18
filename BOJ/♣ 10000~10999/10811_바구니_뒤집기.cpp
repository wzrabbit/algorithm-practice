#include <algorithm>
#include <iostream>
using namespace std;

int basket[101];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N, Q;
    cin >> N >> Q;

    for (int i = 1; i <= N; i++) {
        basket[i] = i;
    }

    while (Q--) {
        int start, end;
        cin >> start >> end;
        reverse(basket + start, basket + end + 1);
    }

    for (int i = 1; i <= N; i++) {
        cout << basket[i] << " ";
    }
}