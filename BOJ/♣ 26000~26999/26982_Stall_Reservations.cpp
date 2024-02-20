#include <algorithm>
#include <iostream>
#include <queue>
#define INF 9'876'543
using namespace std;

struct Period {
    int s, e, i;
};

struct PQData {
    int e, n;
};

bool operator<(const Period& a, const Period& b) {
    return a.s < b.s;
}

bool operator<(const PQData& a, const PQData& b) {
    return a.e > b.e;
}

Period periods[50001];
int selected_rooms[50001];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N;
    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> periods[i].s >> periods[i].e;
        periods[i].i = i;
    }

    sort(periods + 1, periods + N + 1);

    priority_queue<PQData> pq;
    pq.push({INF, 0});

    for (int i = 1; i <= N; i++) {
        if (periods[i].s <= pq.top().e) {
            int next_room_no = (int)pq.size();
            pq.push({periods[i].e, next_room_no});
            selected_rooms[periods[i].i] = next_room_no;
            continue;
        }

        PQData popped = pq.top();
        pq.pop();
        int selected_room_no = popped.n;
        pq.push({periods[i].e, selected_room_no});
        selected_rooms[periods[i].i] = selected_room_no;
    }

    cout << (int)pq.size() - 1 << '\n';

    for (int i = 1; i <= N; i++) {
        cout << selected_rooms[i] << '\n';
    }
}
