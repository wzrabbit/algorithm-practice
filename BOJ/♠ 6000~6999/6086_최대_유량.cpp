/**
 * 최대 유량 구현 연습
 * kks227님의 코드를 참고하여 작성했습니다.
 **/

#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
#define INF 10000
using namespace std;

int capacity[52][52];
int flow[52][52];
vector<int> graph[52];

int char_to_int(char c) {
    if (c >= 'A' && c <= 'Z')
        return c - 'A';
    else
        return c - 'a' + 26;
}

int flow_bfs() {
    int prev[52];
    int total_flow = 0;

    while (true) {
        fill(prev, prev + 52, -1);
        queue<int> q;
        q.push(0);

        while (q.size() && prev[25] == -1) {
            int cur = q.front();
            q.pop();

            for (int i = 0; i < graph[cur].size(); i++) {
                int nxt = graph[cur][i];

                if (flow[cur][nxt] < capacity[cur][nxt] && prev[nxt] == -1) {
                    q.push(nxt);
                    prev[nxt] = cur;
                }
            }
        }

        if (prev[25] == -1) break;

        int path_flow = INF;
        for (int i = 25; i != 0; i = prev[i]) {
            path_flow = min(path_flow, capacity[prev[i]][i] - flow[prev[i]][i]);
        }
        for (int i = 25; i != 0; i = prev[i]) {
            flow[prev[i]][i] += path_flow;
            flow[i][prev[i]] -= path_flow;
        }
        total_flow += path_flow;
    }

    return total_flow;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int E;
    cin >> E;

    for (int i = 0; i < E; i++) {
        char char_s, char_e;
        int s, e, d;
        cin >> char_s >> char_e >> d;
        s = char_to_int(char_s);
        e = char_to_int(char_e);

        capacity[s][e] += d;
        capacity[e][s] += d;
        graph[s].push_back(e);
        graph[e].push_back(s);
    }

    cout << flow_bfs();
}