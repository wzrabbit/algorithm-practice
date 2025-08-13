#include <iostream>
#include <vector>
using namespace std;

struct Answer {
    char d;
    int p;
    string c;
};

char grid[52][52];
vector<Answer> answer;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N;
    cin >> N;

    int start_R, start_C;
    cin >> start_R >> start_C;

    for (int i = 1; i <= N; i++) {
        cin >> (grid[i] + 1);
    }

    for (int i = 1; i < start_C; i++) {
        answer.push_back({'L', start_R, "push"});
    }

    for (int i = start_C + 1; i <= N; i++) {
        answer.push_back({'R', start_R, "push"});
    }

    for (int i = 1; i < start_R; i++) {
        answer.push_back({'U', 1, "push"});
    }

    for (int i = start_R + 1; i <= N; i++) {
        answer.push_back({'D', 1, "push"});
    }

    for (int i = 2; i <= N; i++) {
        if (grid[start_R][i] == '.') {
            answer.push_back({'U', i, "pull"});
        }
    }

    for (int i = start_R - 1; i >= 1; i--) {
        for (int j = 1; j < N; j++) {
            answer.push_back({'R', i, "push"});
        }

        for (int j = 2; j <= N; j++) {
            if (grid[i][j] == '.') {
                answer.push_back({'U', j, "pull"});
            }
        }
    }

    for (int i = start_R + 1; i <= N; i++) {
        for (int j = 1; j < N; j++) {
            answer.push_back({'R', i, "push"});
        }

        for (int j = 2; j <= N; j++) {
            if (grid[i][j] == '.') {
                answer.push_back({'D', j, "pull"});
            }
        }
    }

    for (int i = 1; i <= N; i++) {
        if (grid[i][1] == '.') {
            answer.push_back({'L', i, "pull"});
        }
    }

    cout << answer.size() << '\n';

    for (Answer cur : answer) {
        cout << cur.d << ' ' << cur.p << ' ' << cur.c << '\n';
    }
}
