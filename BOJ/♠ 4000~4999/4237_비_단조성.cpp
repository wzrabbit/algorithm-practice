#include <iostream>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;

        int direction = 1;
        int num = -1;
        int length = 1;

        while (N--) {
            int cur;
            cin >> cur;

            if (direction == 1) {
                if (cur < num) {
                    direction = 0;
                    length += 1;
                }
            } else {
                if (cur > num) {
                    direction = 1;
                    length += 1;
                }
            }

            num = cur;
        }

        cout << length << '\n';
    }
}