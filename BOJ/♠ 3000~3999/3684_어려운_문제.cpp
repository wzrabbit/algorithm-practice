#include <algorithm>
#include <iostream>
using namespace std;

int input[100];
int ans_a, ans_b;

void find_ab(int N) {
    for (int a = 0; a <= 10000; a++) {
        for (int b = 0; b <= 10000; b++) {
            bool success = true;

            for (int i = 0; i < N - 1; i++) {
                if (((input[i] * a + b) % 10001 * a + b) % 10001 != input[i + 1]) {
                    success = false;
                    break;
                }
            }

            if (success) {
                ans_a = a;
                ans_b = b;
                return;
            }
        }
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N;
    cin >> N;

    for (int i = 0; i < N; i++)
        cin >> input[i];

    find_ab(N);

    for (int i = 0; i < N; i++)
        cout << (input[i] * ans_a + ans_b) % 10001 << '\n';
}