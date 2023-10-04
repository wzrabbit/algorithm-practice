#include <iostream>
typedef long long ll;
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    string S;
    ll index;

    cin >> S >> index;
    index -= 1;

    ll area = S.size();

    while (area <= index) {
        area *= 2;
    }

    while (area > S.size()) {
        if (index == area / 2) {
            index -= 1;
        } else if (index > area / 2) {
            index -= area / 2 + 1;
        }

        area /= 2;
    }

    cout << S[index];
}