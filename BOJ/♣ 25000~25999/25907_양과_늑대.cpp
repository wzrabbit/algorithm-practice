#include <algorithm>
#include <iostream>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N;
    cin >> N;

    int start = 1;
    int end = N;
    int mid;
    int sheep_count;

    while (start <= end) {
        mid = (start + end) / 2;
        cout << "? " << mid << endl;

        cin >> sheep_count;
        int wolf_count = mid - sheep_count;

        if (sheep_count > wolf_count) {
            start = mid + 1;
        } else if (sheep_count < wolf_count) {
            end = mid - 1;
        } else {
            cout << "! " << mid << endl;
            break;
        }
    }
}