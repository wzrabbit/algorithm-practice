#include <iostream>
using namespace std;

int main() {
    int G, P, T;
    cin >> G >> P >> T;

    int individual = G * P;
    int group = G + T * P;

    if (individual > group) {
        cout << 2;
    } else if (individual < group) {
        cout << 1;
    } else {
        cout << 0;
    }
}