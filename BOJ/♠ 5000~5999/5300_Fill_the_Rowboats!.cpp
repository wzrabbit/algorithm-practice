#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;

    for (int i = 1; i <= N; i++) {
        cout << i << ' ';
        if (i % 6 == 0 || i == N) {
            cout << "Go! ";
        }
    }
}