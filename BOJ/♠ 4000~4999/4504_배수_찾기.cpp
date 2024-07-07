#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;

    while (true) {
        int cur;
        cin >> cur;

        if (cur == 0) {
            break;
        }

        if (cur % N == 0) {
            cout << cur << " is a multiple of " << N << ".\n";
        } else {
            cout << cur << " is NOT a multiple of " << N << ".\n";
        }
    }
}
