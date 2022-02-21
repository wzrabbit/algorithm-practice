#include <iostream>
#include <algorithm>
#include <deque>
using namespace std;

struct ant {
    int id, value;
};

bool board_sorter(ant a, ant b) {
    return a.value < b.value;
}

bool order_sorter(ant a, ant b) {
    if (a.value < b.value) return true;
    else if (a.value > b.value) return false;
    return a.id < b.id;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int tc;
    cin >> tc;
    while (tc--) {
        int num, len, no, value, id;
        cin >> num >> len >> no;
        deque<ant> board;
        deque<ant> order;
        for (int i = 0; i < num; i++) {
            cin >> value >> id;
            if (id > 0) {
                board.push_back({ id, value });
                order.push_back({ 1, len - value + 1 });
            }
            else {
                board.push_back({ id, value });
                order.push_back({ -1, value + 1 });
            }
        }

        sort(board.begin(), board.end(), board_sorter);
        sort(order.begin(), order.end(), order_sorter);

        for (int i = 0; i < no; i++) {
            ant current = order.front();
            order.pop_front();
            if (order.size() > 0 && current.value == order.front().value) {
                if ((order.front().id == -1 && board.back().id > board.front().id) || (order.front().id == 1 && board.back().id < board.front().id)) {
                    ant temp = order.front();
                    order.pop_front();
                    order.push_front(current);
                    current = temp;
                }
            }

            ant fallen;
            if (current.id == 1) {
                fallen = board.back();
                board.pop_back();
            }
            else {
                fallen = board.front();
                board.pop_front();
            }

            if (i == no - 1) cout << fallen.id << '\n';
        }
    }
}