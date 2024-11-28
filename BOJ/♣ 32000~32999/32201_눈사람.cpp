#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N;
    cin >> N;

    map<int, int> rank;

    for (int i = 1; i <= N; i++) {
        int cur;
        cin >> cur;

        rank[cur] = i;
    }

    int max_diff = -1;
    vector<int> answer;

    for (int i = 1; i <= N; i++) {
        int cur;
        cin >> cur;

        int before_rank = rank[cur];
        int cur_diff = before_rank - i;

        if (cur_diff > max_diff) {
            max_diff = cur_diff;
            answer.clear();
        }

        if (cur_diff >= max_diff) {
            answer.push_back(cur);
        }
    }

    for (size_t i = 0; i < answer.size(); i++) {
        cout << answer[i] << ' ';
    }
}
