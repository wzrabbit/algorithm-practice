#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

struct Query {
    int target, capacity;
};

bool operator<(Query a, Query b) {
    return a.target > b.target;
}

int plan[2001];
vector<Query> query[2001];
int N, C, Q;

void remove_capacity(int capacity) {
    for (int i = N; i >= 1; i--) {
        if (capacity <= 0) {
            return;
        }

        int matched = min(capacity, plan[i]);
        capacity -= matched;
        plan[i] -= matched;
    }
}

void drive_truck_and_print_answer() {
    int current_capacity = 0;
    int delivered = 0;

    for (int i = 1; i <= N; i++) {
        current_capacity -= plan[i];
        delivered += plan[i];
        plan[i] = 0;

        for (size_t j = 0; j < query[i].size(); j++) {
            Query current_query = query[i][j];
            current_capacity += current_query.capacity;
            plan[current_query.target] += current_query.capacity;

            if (current_capacity > C) {
                remove_capacity(current_capacity - C);
                current_capacity = C;
            }
        }
    }

    cout << delivered;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> N >> C >> Q;

    for (int i = 1; i <= Q; i++) {
        int s, t, c;
        cin >> s >> t >> c;

        query[s].push_back({t, c});
    }

    for (int i = 1; i <= N; i++) {
        sort(query[i].begin(), query[i].end());
    }

    drive_truck_and_print_answer();
}