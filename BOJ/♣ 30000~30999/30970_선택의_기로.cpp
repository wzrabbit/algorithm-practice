#include <algorithm>
#include <iostream>
using namespace std;

struct Product {
    int q, p;
};

bool sort_by_quality(Product a, Product b) {
    if (a.q != b.q) {
        return a.q > b.q;
    }

    return a.p < b.p;
}

bool sort_by_price(Product a, Product b) {
    if (a.p != b.p) {
        return a.p < b.p;
    }

    return a.q > b.q;
}

Product products[100001];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N;
    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> products[i].q >> products[i].p;
    }

    sort(products + 1, products + N + 1, sort_by_quality);

    for (int i = 1; i <= 2; i++) {
        cout << products[i].q << ' ' << products[i].p << ' ';
    }

    cout << '\n';

    sort(products + 1, products + N + 1, sort_by_price);

    for (int i = 1; i <= 2; i++) {
        cout << products[i].q << ' ' << products[i].p << ' ';
    }
}
