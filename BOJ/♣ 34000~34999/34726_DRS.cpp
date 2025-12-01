#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Player {
    string name;
    int gap, pos;
};

Player players[200001];
vector<string> DRS_player_names;
int track[6000001];
int prefix[6000001];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N, T;
    cin >> N >> T;

    for (int i = 1; i <= N; i++) {
        cin >> players[i].name >> players[i].gap;
    }

    int cur = 0;

    for (int i = 1; i <= N; i++) {
        cur = (cur + T - players[i].gap % T) % T;
        players[i].pos = cur;
        track[cur] += 1;
        track[cur + T] += 1;
    }

    prefix[0] = track[0];

    for (int i = 1; i < T * 2; i++) {
        prefix[i] = prefix[i - 1] + track[i];
    }

    for (int i = 1; i <= N; i++) {
        if (prefix[players[i].pos + 1000] - prefix[players[i].pos] >= 1) {
            DRS_player_names.push_back(players[i].name);
        }
    }

    sort(DRS_player_names.begin(), DRS_player_names.end());

    if (DRS_player_names.size() == 0) {
        cout << -1;
        return 0;
    }

    for (string name : DRS_player_names) {
        cout << name << ' ';
    }
}
