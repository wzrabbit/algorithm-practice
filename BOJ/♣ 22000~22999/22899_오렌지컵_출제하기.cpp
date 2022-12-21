#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
typedef long long ll;
using namespace std;

struct Problem {
    int priority, time;
};

bool operator<(Problem x, Problem y) {
    return x.priority > y.priority;
}

int author[100001];
int prepare_time[100001];
vector<int> raw[100001];
vector<Problem> problems;
priority_queue<int, vector<int>> times;
ll time_sum = 0;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N, L;
    cin >> N >> L;

    for (int i = 1; i <= N; i++) {
        cin >> author[i];
    }

    for (int i = 1; i <= N; i++) {
        cin >> prepare_time[i];
        raw[author[i]].push_back(prepare_time[i]);
    }

    for (int i = 1; i <= N; i++) {
        sort(raw[i].begin(), raw[i].end());
        for (int j = 0; j < raw[i].size(); j++) {
            problems.push_back({j + 1, raw[i][j]});
        }
    }
    sort(problems.begin(), problems.end());

    for (int i = 1; i <= N; i++) {
        while (!problems.empty() && problems.back().priority <= i) {
            times.push(problems.back().time);
            time_sum += problems.back().time;
            problems.pop_back();
        }

        while (times.size() > L) {
            int popped_time = times.top();
            time_sum -= popped_time;
            times.pop();
        }

        if (times.size() < L) {
            cout << "-1 ";
        } else {
            cout << time_sum << ' ';
        }
    }
}