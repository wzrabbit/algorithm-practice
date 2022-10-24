#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct sch {
    int s, e;
};

bool operator<(sch a, sch b) {
    return a.s < b.s;
}

vector<sch> time_list;
priority_queue<int, vector<int>, greater<int>> nxt;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        int s, e;
        cin >> s >> e;
        time_list.push_back({s, e});
    }

    sort(time_list.begin(), time_list.end());

    int count = 1;
    nxt.push(time_list[0].e);

    for (size_t i = 1; i < time_list.size(); i++) {
        if (time_list[i].s >= nxt.top()) {
            nxt.pop();
            nxt.push(time_list[i].e);
        } else {
            nxt.push(time_list[i].e);
            count++;
        }
    }

    cout << count;
}