#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

struct Value {
    int n, v;
};

bool operator<(const Value& a, const Value& b) {
    return a.v > b.v;
}

int answer[501][501];
int rows[501];
int cols[501];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N;
    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> rows[i];
    }

    for (int i = 1; i <= N; i++) {
        cin >> cols[i];
    }

    for (int r = 1; r <= N; r++) {
        vector<Value> values;

        for (int c = 1; c <= N; c++) {
            values.push_back({c, cols[c]});
        }

        sort(values.begin(), values.end());

        for (size_t c = 0; c < rows[r]; c++) {
            Value cur = values[c];

            if (cur.v == 0) {
                cout << -1;
                return 0;
            }

            cols[cur.n] -= 1;
            answer[r][cur.n] = 1;
        }
    }

    for (int c = 1; c <= N; c++) {
        if (cols[c] != 0) {
            cout << -1;
            return 0;
        }
    }

    cout << 1 << '\n';

    for (int r = 1; r <= N; r++) {
        for (int c = 1; c <= N; c++) {
            cout << answer[r][c];
        }

        cout << '\n';
    }
}
