#include <iostream>
#include <string>
#define MOD 64
using namespace std;

int board[8][8];

void solve_mia() {
    int T;
    cin >> T;

    while (T--) {
        int state = 0;

        for (int r = 0; r < 8; r++) {
            for (int c = 0; c < 8; c++) {
                cin >> board[r][c];
                if (board[r][c] == 1) state ^= r * 8 + c;
            }
        }

        int key;
        cin >> key;
        int have_to_press = state ^ (key - 1);
        board[have_to_press / 8][have_to_press % 8] = 1 - board[have_to_press / 8][have_to_press % 8];

        for (int r = 0; r < 8; r++) {
            for (int c = 0; c < 8; c++) {
                cout << board[r][c] << ' ';
            }
            cout << '\n';
        }
        cout << "---\n";
    }
}

void solve_danila() {
    int T;
    cin >> T;

    while (T--) {
        int key = 0;

        for (int i = 0; i < 64; i++) {
            int cur;
            cin >> cur;
            if (cur == 1) key ^= i;
        }

        string trash;
        cin >> trash;

        cout << key + 1 << '\n';
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    string player;
    cin >> player;

    if (player == "Mia") {
        solve_mia();
    } else {
        solve_danila();
    }
}