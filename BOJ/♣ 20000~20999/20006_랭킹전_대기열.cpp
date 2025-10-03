#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Player {
    int lv;
    string name;
};

bool operator<(const Player &a, const Player &b) { return a.name < b.name; }

vector<vector<Player>> rooms;
int P, M;

void insert_player(Player player) {
    for (vector<Player> &room : rooms) {
        if ((int)room.size() < M && abs(player.lv - room[0].lv) <= 10) {
            room.push_back(player);
            return;
        }
    }

    rooms.push_back({player});
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> P >> M;

    for (int i = 1; i <= P; i++) {
        int lv;
        string name;
        cin >> lv >> name;
        insert_player({lv, name});
    }

    for (vector<Player> &room : rooms) {
        if ((int)room.size() == M) {
            cout << "Started!\n";
        } else {
            cout << "Waiting!\n";
        }

        sort(room.begin(), room.end());

        for (Player player : room) {
            cout << player.lv << ' ' << player.name << '\n';
        }
    }
}
