#include <iostream>
using namespace std;

int main() {
    while (true) {
        double x, y;
        cin >> x >> y;

        if (x == 0 && y == 0) {
            cout << "AXIS\n";
            break;
        }

        if (x == 0 || y == 0) {
            cout << "AXIS\n";
            continue;
        }

        if (x > 0 && y > 0) {
            cout << "Q1\n";
            continue;
        }

        if (x < 0 && y > 0) {
            cout << "Q2\n";
            continue;
        }

        if (x < 0 && y < 0) {
            cout << "Q3\n";
            continue;
        }

        cout << "Q4\n";
    }
}