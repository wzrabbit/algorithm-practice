#include <algorithm>
#include <iostream>
#include <queue>
#define INF 987654321
using namespace std;

int dist[201][201];
int longest[201][201];
int V, E;

void floyd() {
    for (int i = 1; i <= V; i++) {
        dist[i][i] = 0;
    }

    for (int m = 1; m <= V; m++) {
        for (int s = 1; s <= V; s++) {
            for (int e = 1; e <= V; e++) {
                if (dist[s][m] + dist[m][e] < dist[s][e]) {
                    dist[s][e] = dist[s][m] + dist[m][e];
                }
            }
        }
    }
}

void print_answer() {
    int answer = INF;

    for (int i = 1; i <= V; i++) {
        int current = 0;

        for (int a = 1; a <= V; a++) {
            for (int b = 1; b <= V; b++) {
                int l = dist[i][a];
                int r = dist[i][b];

                if (longest[a][b] == 0) {
                    continue;
                }

                int start_time = min(l, r);
                int burn_time = abs(l - r) + (longest[a][b] - abs(l - r)) / 2;

                current = max(current, start_time + burn_time);
            }
        }

        answer = min(answer, current);
    }

    if (answer % 2 == 0) {
        cout << answer / 2 << ".0";
    } else {
        cout << (answer - 1) / 2 << ".5";
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> V >> E;

    fill(&dist[1][1], &dist[V][V + 1], INF);
    fill(&longest[1][1], &longest[V][V + 1], 0);

    for (int i = 1; i <= E; i++) {
        int s, e, d;
        cin >> s >> e >> d;

        dist[s][e] = min(dist[s][e], d * 2);
        dist[e][s] = min(dist[e][s], d * 2);

        longest[s][e] = max(longest[s][e], d * 2);
        longest[e][s] = max(longest[e][s], d * 2);
    }

    floyd();
    print_answer();
}