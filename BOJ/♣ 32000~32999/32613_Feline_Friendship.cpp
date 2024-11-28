#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

vector<int> cycle_sizes;
int next_no[200001];
bool visited[200001];

void find_cycle(int start) {
    int cur_size = 0;
    int cur_no = start;

    while (true) {
        if (visited[cur_no]) {
            break;
        }

        visited[cur_no] = true;
        cur_no = next_no[cur_no];
        cur_size += 1;
    }

    if (cur_size > 0) {
        cycle_sizes.push_back(cur_size);
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N, K;
    cin >> N >> K;

    for (int i = 1; i <= N; i++) {
        cin >> next_no[i];
    }

    for (int i = 1; i <= N; i++) {
        find_cycle(i);
    }

    sort(cycle_sizes.begin(), cycle_sizes.end(), greater<int>());

    for (int cur : cycle_sizes) {
        if (cur == K) {
            cout << 0;
            return 0;
        }
    }

    if (cycle_sizes[0] > K) {
        cout << 1;
        return 0;
    }

    int convince_count = -1;
    int group_size = 0;

    for (int cur : cycle_sizes) {
        group_size += cur;
        convince_count += 1;

        if (group_size >= K) {
            break;
        }
    }

    cout << convince_count;
}
