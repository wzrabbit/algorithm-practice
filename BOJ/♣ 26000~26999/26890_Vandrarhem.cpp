#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

struct Room {
    int price, limit;
};

bool operator<(Room a, Room b) {
    return a.price < b.price;
}

vector<Room> rooms;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N, M;
    cin >> N >> M;

    for (int i = 0; i < M; i++) {
        Room cur;
        cin >> cur.price >> cur.limit;
        rooms.push_back(cur);
    }

    sort(rooms.begin(), rooms.end());

    int total_price = 0;
    int remaining = N;
    for (size_t i = 0; i < rooms.size(); i++) {
        int matched = min(remaining, rooms[i].limit);
        total_price += matched * rooms[i].price;
        remaining -= matched;

        if (remaining == 0) {
            break;
        }
    }

    cout << total_price;
}