#include <deque>
#include <iostream>
#include <string>
#define WALL 0
#define BALL 1
using namespace std;

deque<int> q;
int direction = 3;
int wall_count = 0;
int ball_count = 0;

void push() {
    string type;
    cin >> type;

    if (type == "b") {
        q.push_back(BALL);
        ball_count += 1;
    } else {
        q.push_back(WALL);
        wall_count += 1;
    }
}

void pop() {
    if (q.empty()) {
        return;
    }

    int popped = q.front();
    q.pop_front();

    if (popped == BALL) {
        ball_count -= 1;
    } else {
        wall_count -= 1;
    }
}

void rotate() {
    string type;
    cin >> type;

    if (type == "l") {
        direction = (direction + 3) % 4;
    } else {
        direction = (direction + 1) % 4;
    }
}

void print_count() {
    string type;
    cin >> type;

    if (type == "b") {
        cout << ball_count << '\n';
    } else {
        cout << wall_count << '\n';
    }
}

void drop() {
    if (direction == 0) {
        while (!q.empty() && q.front() == BALL) {
            q.pop_front();
            ball_count -= 1;
        }
    } else if (direction == 2) {
        while (!q.empty() && q.back() == BALL) {
            q.pop_back();
            ball_count -= 1;
        }
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int Q;
    cin >> Q;

    while (Q--) {
        string query;
        cin >> query;

        if (query == "push") push();
        if (query == "pop") pop();
        if (query == "rotate") rotate();
        if (query == "count") print_count();

        drop();
    }
}