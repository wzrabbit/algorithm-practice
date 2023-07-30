#include <iostream>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int A, B, C, D, E, F;
    cin >> A >> B >> C >> D >> E >> F;

    for (int x = -999; x <= 999; x++) {
        for (int y = -999; y <= 999; y++) {
            if (A * x + B * y == C && D * x + E * y == F) {
                cout << x << ' ' << y;
                return 0;
            }
        }
    }
}