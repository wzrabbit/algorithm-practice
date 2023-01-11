#include <iostream>
using namespace std;

int main() {
    int muffin;
    cin >> muffin;

    int turn = 1;
    int result[2] = {0, 0};

    while (muffin > 0) {
        int matched = muffin - muffin / 2;
        result[turn] += matched;
        muffin -= matched;
        turn = 1 - turn;
    }

    cout << result[0] << ' ' << result[1];
}