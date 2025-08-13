#include <iostream>
#define MAX 1'000'000'000
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int start = 1;
    int end = MAX;

    for (int i = 1; i <= 100; i++) {
        int guess;
        cin >> guess;

        if (guess < start) {
            cout << '>' << endl;
            continue;
        }

        if (guess > end) {
            cout << '<' << endl;
            continue;
        }

        if (start == end) {
            cout << '=' << endl;
            return 0;
        }

        int left_size = guess - start + 1;
        int right_size = end - guess;

        if (left_size >= right_size) {
            end = guess - 1;
            cout << '<' << endl;
            continue;
        }

        start = guess + 1;
        cout << '>' << endl;
    }
}
