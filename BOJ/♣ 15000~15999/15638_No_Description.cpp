#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;

    for (int i = 2; i * i <= N; i++) {
        if (N % i == 0) {
            cout << "No";
            return 0;
        }
    }

    cout << "Yes";
}
