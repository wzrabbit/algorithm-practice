#include <algorithm>
#include <iostream>
using namespace std;

int main() {
    int B, W;
    cin >> B >> W;

    if (B < W) {
        swap(B, W);
    }

    for (int i = 45678; i >= 1; i--) {
        if (i % 2 == 0 && W >= i * i / 2) {
            cout << i;
            return 0;
        }

        if (i % 2 == 1 && B >= i * i / 2 + 1 && W >= i * i / 2) {
            cout << i;
            return 0;
        }
    }
}