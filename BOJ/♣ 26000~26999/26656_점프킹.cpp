#include <algorithm>
#include <iostream>
#include <vector>
#define TRAP 1
#define EXIT 2
using namespace std;

int moves[1001][1001];
char direction[1002][1002];
int parent[1000001];
int state[1000001];
int scale[1000001];
int visited[1001][1001];
vector<int> trap_scales;
vector<int> exit_scales;
int exit_scales_total = 0;
int R, C, K;

int get_parent(int child) {
    if (parent[child] == 0)
        return child;

    return parent[child] = get_parent(parent[child]);
}

void merge(int a, int b) {
    a = get_parent(a);
    b = get_parent(b);

    if (a == b) return;

    if (a < b) {
        parent[b] = a;
        state[b] = a;
        state[b] = 0;
        scale[a] += scale[b];
    } else {
        parent[a] = b;
        state[a] = b;
        state[a] = 0;
        scale[b] += scale[a];
    }
}

void set_state(int child, int new_state) {
    int cur_parent = get_parent(child);
    state[cur_parent] = new_state;
}

bool is_outside(int no, int next_r, int next_c) {
    if (next_r <= 0 || next_r > R || next_c <= 0 || next_c > C) {
        set_state(no, EXIT);
        return true;
    }

    return false;
}

int get_id(int cur_r, int cur_c) {
    return (cur_r - 1) * C + cur_c;
}

void traverse(int cur_r, int cur_c) {
    if (visited[cur_r][cur_c] != 0) return;

    int no = get_id(cur_r, cur_c);

    while (true) {
        if (visited[cur_r][cur_c] != 0) {
            set_state(no, TRAP);
            merge(visited[cur_r][cur_c], no);
            return;
        }

        visited[cur_r][cur_c] = no;
        merge(get_id(cur_r, cur_c), no);

        int next_r = cur_r;
        int next_c = cur_c;

        switch (direction[cur_r][cur_c]) {
            case 'U':
                next_r -= moves[cur_r][cur_c];
                break;
            case 'D':
                next_r += moves[cur_r][cur_c];
                break;
            case 'L':
                next_c -= moves[cur_r][cur_c];
                break;
            case 'R':
                next_c += moves[cur_r][cur_c];
                break;
        }

        if (is_outside(no, next_r, next_c)) {
            return;
        }

        cur_r = next_r;
        cur_c = next_c;
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> R >> C >> K;

    fill(scale + 1, scale + R * C + 1, 1);

    for (int r = 1; r <= R; r++) {
        for (int c = 1; c <= C; c++) {
            cin >> direction[r][c];
        }
    }

    for (int r = 1; r <= R; r++) {
        for (int c = 1; c <= C; c++) {
            cin >> moves[r][c];
        }
    }

    for (int r = 1; r <= R; r++) {
        for (int c = 1; c <= C; c++) {
            traverse(r, c);
        }
    }

    for (int i = 1; i <= R * C; i++) {
        if (state[i] == TRAP) {
            trap_scales.push_back(scale[i]);
            continue;
        }

        if (state[i] == EXIT) {
            exit_scales.push_back(scale[i]);
            exit_scales_total += scale[i];
        }
    }

    sort(trap_scales.begin(), trap_scales.end(), greater<int>());
    sort(exit_scales.begin(), exit_scales.end(), greater<int>());

    int min_answer = exit_scales_total;
    int max_answer = exit_scales_total;

    for (int i = 0; i < min((int)exit_scales.size(), K); i++) {
        min_answer -= exit_scales[i];
    }

    for (int i = 0; i < min((int)trap_scales.size(), K); i++) {
        max_answer += trap_scales[i];
    }

    cout << min_answer << ' ' << max_answer;
}
4