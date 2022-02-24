#include <iostream>
#include <queue>
#include <regex>
#include <string>
#include <vector>
using namespace std;

char maze[101][101];
bool visited[101][102];
bool keys[27];
int dr[4] = { -1, 1, 0, 0 };
int dc[4] = { 0, 0, -1, 1 };
regex re(R"([.$a-z])");
regex re2(R"([a-z])");

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int tc, row, col;
    string keyString;

    cin >> tc;
    while (tc--) {
        queue<pair<int, int>> que;
        vector<vector<pair<int, int>>> blockedArea(26);
        int cnt = 0;
        char d;
        fill(&visited[0][0], &visited[100][101], false);
        fill(&keys[0], &keys[26], false);

        cin >> row >> col;
        for (int r = 0; r < row; r++) {
            for (int c = 0; c < col; c++) {
                cin >> d;
                maze[r][c] = d;
            }
        }

        cin >> keyString;
        if (keyString != "0") {
            for (int i = 0; i < keyString.length(); i++) {
                keys[keyString[i] - 'a'] = true;
            }
        }

        for (int r = 0; r < row; r++) {
            for (int i = 0; i < 2; i++) {
                int u = 0;
                if (i == 1) u = col - 1;
                if (regex_match(&maze[r][u], &maze[r][u] + 1, re)) {
                    visited[r][u] = true;
                    que.push(make_pair(r, u));
                }
                else if (maze[r][u] != '*') {
                    if (keys[maze[r][u] - 'A']) {
                        visited[r][u] = true;
                        que.push(make_pair(r, u));
                    }
                    else {
                        visited[r][u] = true;
                        blockedArea[maze[r][u] - 'A'].push_back(make_pair(r, u));
                    }
                }
            }
        }

        for (int c = 1; c < col - 1; c++) {
            for (int i = 0; i < 2; i++) {
                int u = 0;
                if (i == 1) u = row - 1;
                if (regex_match(&maze[u][c], &maze[u][c] + 1, re)) {
                    visited[u][c] = true;
                    que.push(make_pair(u, c));
                }
                else if (maze[u][c] != '*') {
                    if (keys[maze[u][c] - 'A']) {
                        visited[u][c] = true;
                        que.push(make_pair(u, c));
                    }
                    else {
                        visited[u][c] = true;
                        blockedArea[maze[u][c] - 'A'].push_back(make_pair(u, c));
                    }
                }
            }
        }

        while (que.size()) {
            int ro = que.front().first;
            int co = que.front().second;
            que.pop();

            if (regex_match(&maze[ro][co], &maze[ro][co] + 1, re2)) {
                keys[maze[ro][co] - 'a'] = true;
                for (int i = 0; i < blockedArea[maze[ro][co] - 'a'].size(); i++) {
                    que.push(blockedArea[maze[ro][co] - 'a'][i]);
                }
            }
            else if (maze[ro][co] == '$') {
                cnt++;
            }

            for (int i = 0; i < 4; i++) {
                int r = ro + dr[i];
                int c = co + dc[i];

                if (r >= 0 && r < row && c >= 0 && c < col && visited[r][c] == false) {
                    if (regex_match(&maze[r][c], &maze[r][c] + 1, re)) {
                        visited[r][c] = true;
                        que.push(make_pair(r, c));
                    }
                    else if (maze[r][c] != '*') {
                        if (keys[maze[r][c] - 'A']) {
                            visited[r][c] = true;
                            que.push(make_pair(r, c));
                        }
                        else {
                            visited[r][c] = true;
                            blockedArea[maze[r][c] - 'A'].push_back(make_pair(r, c));
                        }
                    }
                }
            }
        }

        cout << cnt << '\n';
    }
}