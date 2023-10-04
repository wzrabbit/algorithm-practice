#include <algorithm>
#include <iostream>
#include <queue>
typedef long long ll;
using namespace std;

struct Problem {
    ll d, p;
};

struct IdeaSort {
    bool operator()(const Problem &a, const Problem &b) {
        return a.d > b.d;
    }
};

struct ImplSort {
    bool operator()(const Problem &a, const Problem &b) {
        return a.p > b.p;
    }
};

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N, M;
    cin >> N >> M;

    priority_queue<Problem, vector<Problem>, IdeaSort> pq;
    priority_queue<Problem, vector<Problem>, ImplSort> solvable_pq;

    for (int i = 1; i <= N; i++) {
        ll D, P, T, E;
        cin >> D >> P >> T >> E;

        if (T == 1) {
            P = 0;
        }

        if (E == 1) {
            pq.push({D - D / 2, P / 2});
        } else {
            pq.push({D, P});
        }
    }

    ll hb_idea, hb_impl;
    cin >> hb_idea >> hb_impl;

    bool success = true;
    ll wrong = 0;

    for (int i = 1; i <= M; i++) {
        while (!pq.empty() && hb_idea >= pq.top().d) {
            Problem popped_problem = pq.top();
            pq.pop();

            solvable_pq.push(popped_problem);
        }

        if (solvable_pq.empty()) {
            success = false;
            break;
        }

        Problem cur = solvable_pq.top();
        solvable_pq.pop();

        wrong += max(0ll, cur.p - hb_impl);
        hb_idea += 1;
        hb_impl += 1;
    }

    if (success) {
        cout << wrong;
    } else {
        cout << -1;
    }
}