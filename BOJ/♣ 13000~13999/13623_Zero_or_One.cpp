#include <iostream>
using namespace std;

int main() {
    int A, B, C;
    cin >> A >> B >> C;

    if (A == B && B == C) {
        cout << "*";
        return 0;
    }

    if (B == C) {
        cout << "A";
        return 0;
    }

    if (A == C) {
        cout << "B";
        return 0;
    }

    cout << "C";
}