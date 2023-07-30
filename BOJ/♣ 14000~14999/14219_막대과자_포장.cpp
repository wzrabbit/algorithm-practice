#include <iostream>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    if (N * M % 3 == 0) {
        cout << "YES";
    } else {
        cout << "NO";
    }
}