#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
using namespace std;

struct QData {
    int n, d;
};

char input[4][4];
bool visited[1024];
vector<int> next_bits[9] = {
    {1, 3},
    {0, 2, 4},
    {1, 5},
    {0, 4, 6},
    {1, 3, 5, 7},
    {2, 4, 8},
    {3, 7},
    {4, 6, 8},
    {5, 7}};

void get_input() {
    for (int r = 0; r < 3; r++) {
        cin >> input[r];
    }
}

int get_bit_number() {
    int bit = 0;

    for (int r = 0; r < 3; r++) {
        for (int c = 0; c < 3; c++) {
            if (input[r][c] == '*') {
                bit += (1 << (r * 3 + c));
            }
        }
    }

    return bit;
}

int get_click_needed(int goal) {
    fill(visited, visited + 1024, false);
    queue<QData> q;
    q.push({0, 0});
    visited[0] = true;

    while (!q.empty()) {
        QData cur = q.front();
        q.pop();

        if (cur.n == goal) {
            return cur.d;
        }

        for (int i = 0; i < 9; i++) {
            int next_bit = cur.n;

            next_bit ^= (1 << i);

            for (size_t j = 0; j < next_bits[i].size(); j++) {
                next_bit ^= (1 << next_bits[i][j]);
            }

            if (!visited[next_bit]) {
                visited[next_bit] = true;
                q.push({next_bit, cur.d + 1});
            }
        }
    }

    return -1;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int T;
    cin >> T;

    while (T--) {
        get_input();
        int goal = get_bit_number();

        cout << get_click_needed(goal) << '\n';
    }
}
