#include <iostream>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    
    if (N > 7) {
        cout << N - 7;
    } else {
        cout << M + 7;
    }
}