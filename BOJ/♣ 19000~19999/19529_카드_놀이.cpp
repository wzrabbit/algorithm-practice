#include <iostream>
#include <vector>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int T;
    cin >> T;

    while (T--) {
        int N, X;
        cin >> N >> X;

        int sum = N * (N + 1) / 2;

        if (sum % 2 != abs(X) % 2) {
            cout << "NO\n";
            continue;
        }

        vector<int> alice_cards, bob_cards;
        int goal_number = (sum + X) / 2;

        if (N % 2 == 1) {
            goal_number -= 1;
        }

        int left_value = goal_number;
        int left_count = N / 2;
        bool success = true;

        for (int i = N; i >= 2; i--) {
            int min_left_value =
                left_count * (left_count - 1) / 2 + (left_count - 1);

            if (left_count > 0 && left_value - i >= min_left_value) {
                alice_cards.push_back(i);
                left_value -= i;
                left_count -= 1;
            } else {
                bob_cards.push_back(i);
            }
        }

        if (left_count > 0 || left_value > 0) {
            success = false;
        }

        if (!success) {
            cout << "NO\n";
            continue;
        }

        cout << "YES\n";

        for (int i = 0; i < N / 2; i++) {
            cout << alice_cards[i] << ' ';

            if (i < int(bob_cards.size())) {
                cout << bob_cards[i] << ' ';
            }
        }

        cout << 1 << "\n";
    }
}
