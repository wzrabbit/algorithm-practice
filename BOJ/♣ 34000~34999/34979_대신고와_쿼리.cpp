#include <iostream>
using namespace std;

int dr[5] = {0, 0, 0, -1, 1};
int dc[5] = {0, -1, 1, 0, 0};
int grid[5][1001];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N, Q;
    cin >> N >> Q;

    while (Q--) {
        int type;
        cin >> type;

        if (type == 1) {
            int a, b;
            cin >> a >> b;

            for (int i = 0; i < 5; i++) {
                int na = a + dr[i];
                int nb = b + dc[i];

                if (na >= 1 && na <= 4 && nb >= 1 && nb <= N) {
                    grid[na][nb] += 1;
                }
            }

            continue;
        }

        int a;
        cin >> a;
        int worst_class = 0;
        int worst_disgust = -1;

        for (int i = 1; i <= N; i++) {
            if (grid[a][i] > worst_disgust) {
                worst_disgust = grid[a][i];
                worst_class = i;
            }
        }

        cout << worst_class << "\n";
    }

    int worst_class = 0;
    int worst_floor = 0;
    int worst_disgust = -1;

    for (int i = 1; i <= 4; i++) {
        for (int j = 1; j <= N; j++) {
            if (grid[i][j] > worst_disgust) {
                worst_disgust = grid[i][j];
                worst_floor = i;
                worst_class = j;
            }
        }
    }

    cout << worst_floor << " " << worst_class << "\n";
}
