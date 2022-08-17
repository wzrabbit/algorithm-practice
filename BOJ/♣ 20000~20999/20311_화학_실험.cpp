
#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct pq_data {
    int num, amount;
};

bool operator<(pq_data a, pq_data b) {
    if (a.amount != b.amount)
        return a.amount < b.amount;

    return a.num > b.num;
}

vector<int> answer;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N, K;
    cin >> N >> K;
    int success = true;

    priority_queue<pq_data> pq;

    for (int i = 1; i <= K; i++) {
        int x;
        cin >> x;

        pq.push({i, x});
    }

    while (pq.size() >= 2) {
        pq_data first_ = pq.top();
        pq.pop();
        pq_data second_ = pq.top();
        pq.pop();

        answer.push_back(first_.num);
        answer.push_back(second_.num);
        first_.amount--;
        second_.amount--;

        if (first_.amount > 0)
            pq.push(first_);

        if (second_.amount > 0)
            pq.push(second_);
    }

    if (pq.size() == 1) {
        pq_data left = pq.top();
        pq.pop();

        if (left.amount > 1)
            success = false;
        else
            answer.push_back(left.num);
    }

    if (success) {
        for (size_t i = 0; i < answer.size(); i++)
            cout << answer[i] << ' ';
    } else
        cout << -1;
}