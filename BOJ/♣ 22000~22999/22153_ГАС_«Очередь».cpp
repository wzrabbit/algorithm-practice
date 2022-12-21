#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
typedef long long ll;
using namespace std;

struct Quest {
    int time, anger;
};

bool operator<(Quest x, Quest y) {
    return x.anger < y.anger;
}

bool time_sort(Quest x, Quest y) {
    return x.time < y.time;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int T;
    cin >> T;

    while (T--) {
        vector<Quest> quests;
        priority_queue<Quest> pq;
        int index = 0;
        int time = 1;
        ll cur_anger = 0;
        ll total_anger = 0;

        int N;
        cin >> N;

        for (int i = 0; i < N; i++) {
            Quest cur_quest;
            cin >> cur_quest.time >> cur_quest.anger;
            quests.push_back(cur_quest);
        }

        sort(quests.begin(), quests.end(), time_sort);

        while (index < N || pq.size() > 0) {
            while (index < N && quests[index].time <= time) {
                pq.push(quests[index]);
                cur_anger += quests[index].anger;
                index++;
            }

            if (!pq.empty()) {
                Quest resolved_quest = pq.top();
                pq.pop();
                cur_anger -= resolved_quest.anger;
                total_anger += cur_anger;
                time++;
            } else if (index < N) {
                time = quests[index].time;
            }
        }

        cout << total_anger << '\n';
    }
}