#include <algorithm>
#include <iostream>
using namespace std;

bool appeared[3];
int best = 0;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N;
    cin >> N;

    int zero_one_two = -1;  // 0 1 2
    int zero_two = -1;      // 0 2
    int one_two = -1;       // 1 2

    for (int i = 0; i < N; i++) {
        int cur;
        cin >> cur;

        if (cur == 0) {
            if (zero_one_two == -1) zero_one_two = 0;
            if (zero_two == -1) zero_two = 0;
        } else if (cur == 1) {
            if (zero_one_two == 0) zero_one_two = 1;
            if (one_two == -1) one_two = 1;
        } else if (cur == 2) {
            if (zero_one_two == 1) zero_one_two = 2;
            if (zero_two == 0) zero_two = 2;
            if (one_two == 1) one_two = 2;
        }
    }

    if (zero_one_two == 2)
        cout << 3;
    else if (zero_one_two == 1 || zero_two == 1 || one_two == 2)
        cout << 2;
    else
        cout << 1;
}