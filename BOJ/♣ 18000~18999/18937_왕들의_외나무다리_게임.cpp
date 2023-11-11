#include <iostream>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N;
    cin >> N;

    int result_xor = 0;

    for (int i = 1; i <= N; i++) {
        int cur;
        cin >> cur;

        result_xor ^= (cur - 2);
    }

    string start_king;
    cin >> start_king;

    if (start_king == "Whiteking") {
        if (result_xor == 0) {
            cout << "Blackking";
        } else {
            cout << "Whiteking";
        }
    } else {
        if (result_xor == 0) {
            cout << "Whiteking";
        } else {
            cout << "Blackking";
        }
    }
}