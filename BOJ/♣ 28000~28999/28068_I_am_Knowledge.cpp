#include <algorithm>
#include <iostream>
#include <vector>
typedef long long ll;
using namespace std;

struct Book {
    ll cost, reward;
};

bool book_sort(const Book& a, const Book& b) {
    return a.cost < b.cost;
}

vector<Book> positive;
vector<Book> negative;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N;
    cin >> N;

    for (int i = 1; i <= N; i++) {
        int c, r;
        cin >> c >> r;

        if (c <= r) {
            positive.push_back({c, r});
        } else {
            negative.push_back({r, c});
        }
    }

    sort(positive.begin(), positive.end(), book_sort);
    sort(negative.begin(), negative.end(), book_sort);

    ll happiness = 0;

    for (size_t i = 0; i < positive.size(); i++) {
        if (happiness < positive[i].cost) {
            cout << 0;
            return 0;
        }

        happiness += positive[i].reward - positive[i].cost;
    }

    ll evilness = 0;

    for (size_t i = 0; i < negative.size(); i++) {
        if (evilness < negative[i].cost) {
            evilness = negative[i].cost;
        }

        evilness += negative[i].reward - negative[i].cost;
    }

    if (happiness >= evilness) {
        cout << 1;
    } else {
        cout << 0;
    }
}