#include <iostream>
using namespace std;
int N;

int is_prime(int num) {
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return false;
        }
    }

    return true;
}

void backtracking(int num, int step) {
    if (!is_prime(num)) {
        return;
    }

    if (step == N) {
        cout << num << '\n';
        return;
    }

    for (int i = 0; i <= 9; i++) {
        backtracking(num * 10 + i, step + 1);
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N;

    for (int i = 2; i <= 9; i++) {
        backtracking(i, 1);
    }
}