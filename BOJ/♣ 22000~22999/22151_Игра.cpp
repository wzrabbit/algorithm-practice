#include <algorithm>
#include <iostream>
using namespace std;

int main() {
    int T;
    cin >> T;

    while (T--) {
        int limit, start_r, start_c, end_r, end_c;
        cin >> limit >> start_r >> start_c >> end_r >> end_c;

        int dist = abs(start_r - end_r) + abs(start_c - end_c);

        if (dist <= limit) {
            cout << "First 1\n";
        } else {
            cout << "Infinity\n";
        }
    }
}