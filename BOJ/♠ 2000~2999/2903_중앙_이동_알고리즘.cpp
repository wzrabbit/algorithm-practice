#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;

    int width = 2;

    for (int i = 1; i <= N; i++) {
        width = width * 2 - 1;
    }

    cout << width * width;
}