#include <iostream>
using namespace std;

int main() {
    int X;
    cin >> X;

    int up = 1;
    int down = 1;
    int no = 1;
    int direction = 0;

    while (no < X) {
        if (direction == 0) {
            if (up == 1) {
                down += 1;
                direction = 1 - direction;
            } else {
                up -= 1;
                down += 1;
            }
        } else {
            if (down == 1) {
                up += 1;
                direction = 1 - direction;
            } else {
                up += 1;
                down -= 1;
            }
        }

        no += 1;
    }

    cout << up << '/' << down;
}