#include <algorithm>
#include <iostream>
using namespace std;

int db[13001];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N;
    cin >> N;

    int result_price = 10000;

    for (int i = 1; i <= N; i++) {
        int offer, offer_count, type;
        cin >> offer >> offer_count >> type;

        if ((type == 1 && db[offer] < 0) || (type == -1 && db[offer] > 0)) {
            result_price = offer;
        }

        db[offer] += type * offer_count;
    }

    cout << result_price;
}
