#include <iostream>
using namespace std;

int main() {
    int A, B;
    cin >> A >> B;

    if (A <= 50 && B <= 10) {
        cout << "White";
        return 0;
    }

    if (B > 30) {
        cout << "Red";
        return 0;
    }

    cout << "Yellow";
}
