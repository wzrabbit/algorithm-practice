#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;

    int cur = 10;

    while (N > cur) {
        int rem = N % cur;

        if (rem * 2 >= cur) {
            N += cur;
        }

        N -= rem;
        cur *= 10;
    }

    cout << N;
}
