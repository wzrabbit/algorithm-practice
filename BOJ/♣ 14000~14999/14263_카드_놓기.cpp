#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>
#define INF 100000
using namespace std;

struct Range {
    int sr, sc, er, ec;
};

char board[51][51];
int indegree[62];
Range range[62];
bool is_exist[62];
bool is_connected[62][62];
bool visited[62];
string answer;
bool success = true;
int element_count = 0;

int R, C;

int convert_char_to_int(char ch) {
    if (ch >= 'A' && ch <= 'Z') {
        return ch - 'A' + 10;
    }

    if (ch >= 'a' && ch <= 'z') {
        return ch - 'a' + 36;
    }

    return ch - '0';
}

char convert_int_to_char(int num) {
    if (num >= 10 && num <= 35) {
        return 'A' + num - 10;
    }

    if (num >= 36 && num <= 61) {
        return 'a' + num - 36;
    }

    return '0' + num;
}

void set_block_ranges() {
    for (int i = 0; i < 62; i++) {
        range[i] = {INF, INF, 0, 0};
    }

    for (int r = 0; r < R; r++) {
        for (int c = 0; c < C; c++) {
            if (board[r][c] == '.') continue;

            int i = convert_char_to_int(board[r][c]);
            is_exist[i] = true;

            range[i].sr = min(range[i].sr, r);
            range[i].sc = min(range[i].sc, c);
            range[i].er = max(range[i].er, r);
            range[i].ec = max(range[i].ec, c);
        }
    }
}

void count_elements() {
    for (int i = 0; i < 62; i++) {
        if (is_exist[i]) {
            element_count += 1;
        }
    }
}

void set_indegrees() {
    for (int i = 0; i < 62; i++) {
        if (!is_exist[i]) continue;

        for (int r = range[i].sr; r <= range[i].er; r++) {
            for (int c = range[i].sc; c <= range[i].ec; c++) {
                int cur = board[r][c];

                if (cur != convert_int_to_char(i)) {
                    if (cur == '.') {
                        success = false;
                        return;
                    }

                    int converted = convert_char_to_int(cur);

                    if (!is_connected[i][converted]) {
                        indegree[converted] += 1;
                        is_connected[i][converted] = true;
                    }
                }
            }
        }
    }
}

void traverse_and_print_result() {
    if (!success) return;

    priority_queue<int, vector<int>, greater<int>> pq;
    int visited_count = 0;

    for (int i = 0; i < 62; i++) {
        if (is_exist[i] && indegree[i] == 0) {
            pq.push(i);
        }
    }

    while (!pq.empty()) {
        int cur = pq.top();
        pq.pop();

        visited_count += 1;
        answer += convert_int_to_char(cur);

        for (int i = 0; i < 62; i++) {
            if (!is_connected[cur][i]) continue;

            is_connected[cur][i] = false;
            indegree[i] -= 1;

            if (indegree[i] == 0) {
                pq.push(i);
            }
        }
    }

    if (visited_count != element_count) {
        success = false;
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> R >> C;

    for (int r = 0; r < R; r++) {
        cin >> board[r];
    }

    set_block_ranges();
    count_elements();
    set_indegrees();
    traverse_and_print_result();

    if (success) {
        cout << answer;
    } else {
        cout << -1;
    }
}
