#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct Node {
    int no;
    char color;
};

struct PQData {
    int no, moved, score;
};

bool operator<(const PQData x, PQData y) {
    return x.score < y.score;
}

char card_colors[1002];
int max_scores[501][1001];
vector<Node> graph[501];
int N, M, K;

void dijkstra() {
    priority_queue<PQData> pq;
    pq.push({1, 0, 0});

    while (!pq.empty()) {
        PQData cur = pq.top();
        pq.pop();

        if (cur.score < max_scores[cur.no][cur.moved] || cur.moved == N) {
            continue;
        }

        for (size_t i = 0; i < graph[cur.no].size(); i++) {
            Node nxt = graph[cur.no][i];
            int nxt_score = cur.score;

            if (nxt.color == card_colors[cur.moved + 1]) {
                nxt_score += 10;
            }

            if (nxt_score > max_scores[nxt.no][cur.moved + 1]) {
                max_scores[nxt.no][cur.moved + 1] = nxt_score;
                pq.push({nxt.no, cur.moved + 1, nxt_score});
            }
        }
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> card_colors[i];
    }

    cin >> M >> K;

    for (int i = 1; i <= K; i++) {
        int start, end;
        char path_color;
        cin >> start >> end >> path_color;

        graph[start].push_back({end, path_color});
        graph[end].push_back({start, path_color});
    }

    dijkstra();

    int answer = 0;
    for (int i = 1; i <= M; i++) {
        answer = max(answer, max_scores[i][N]);
    }

    cout << answer;
}