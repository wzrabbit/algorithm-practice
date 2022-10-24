#include <algorithm>
#include <iostream>
#include <map>
typedef long long ll;
using namespace std;

int grid[257][257];
int prefix[257][257];
map<int, int> mod_map;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int R, C, MOD;
    cin >> R >> C >> MOD;

    for (int r = 1; r <= R; r++) {
        for (int c = 1; c <= C; c++) {
            cin >> grid[r][c];
            prefix[r][c] = prefix[r - 1][c] + prefix[r][c - 1] - prefix[r - 1][c - 1] + grid[r][c];
        }
    }

    ll answer = 0;
    for (int s = 0; s <= R - 1; s++) {
        for (int e = s + 1; e <= R; e++) {
            ll cur = 0;
            mod_map.clear();
            mod_map[0] = 1;

            for (int i = 1; i <= C; i++) {
                cur = (cur + prefix[e][i] - prefix[s][i] - prefix[e][i - 1] + prefix[s][i - 1]) % MOD;
                if (mod_map.count(cur))
                    mod_map[cur]++;
                else
                    mod_map[cur] = 1;
            }

            for (auto it = mod_map.begin(); it != mod_map.end(); it++) {
                int x = it->second;
                answer += x * (x - 1) / 2;
            }
        }
    }

    cout << answer;
}