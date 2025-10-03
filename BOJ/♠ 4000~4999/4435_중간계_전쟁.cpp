#include <iostream>
using namespace std;

int allies[6];
int enemies[7];

int main() {
    int T;
    cin >> T;

    for (int t = 1; t <= T; t++) {
        for (int i = 0; i < 6; i++) {
            cin >> allies[i];
        }

        for (int i = 0; i < 7; i++) {
            cin >> enemies[i];
        }

        int ally_score = allies[0] + allies[1] * 2 + allies[2] * 3 +
                         allies[3] * 3 + allies[4] * 4 + allies[5] * 10;
        int enemy_score = enemies[0] +
                          (enemies[1] + enemies[2] + enemies[3]) * 2 +
                          enemies[4] * 3 + enemies[5] * 5 + enemies[6] * 10;

        cout << "Battle " << t << ": ";

        if (ally_score > enemy_score) {
            cout << "Good triumphs over Evil";
        } else if (ally_score < enemy_score) {
            cout << "Evil eradicates all trace of Good";
        } else {
            cout << "No victor on this battle field";
        }

        cout << '\n';
    }
}
