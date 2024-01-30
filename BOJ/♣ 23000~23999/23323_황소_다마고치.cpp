#include <iostream>
typedef long long ll;
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int T;
    cin >> T;

    while (T--) {
        ll hp, food;
        cin >> hp >> food;

        ll days = 0;

        while (hp > 0) {
            hp /= 2;
            days += 1;
        }

        days += food;

        cout << days << '\n';
    }
}
