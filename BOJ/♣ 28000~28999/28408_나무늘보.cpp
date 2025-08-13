#include <iostream>
#include <queue>
#include <vector>
#define MOD 998'244'353
using namespace std;

int in[500001];
int out[500001];
int in_index[500001];
int out_index[500001];
int N;

int get_answer() {
    int answer = 1;
    int node_count = 1;
    queue<int> q;
    q.push(in[1]);

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        if (in_index[cur] == N || out_index[cur] == 1) {
            continue;
        }

        int left_candidate = in[in_index[cur] + 1];

        if (out_index[cur] > out_index[left_candidate]) {
            node_count += 1;
            q.push(left_candidate);
        }

        int right_candidate = out[out_index[cur] - 1];

        if (in_index[cur] < in_index[right_candidate]) {
            if (left_candidate == right_candidate) {
                answer = (answer * 2) % MOD;
            } else {
                node_count += 1;
                q.push(right_candidate);
            }
        }
    }

    if (node_count != N) {
        return 0;
    }

    return answer;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> in[i];
        in_index[in[i]] = i;
    }

    for (int i = 1; i <= N; i++) {
        cin >> out[i];
        out_index[out[i]] = i;
    }

    cout << get_answer();
}
