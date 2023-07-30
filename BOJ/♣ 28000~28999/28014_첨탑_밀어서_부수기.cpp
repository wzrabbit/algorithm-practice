#include <iostream>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N;
    cin >> N;

    int prev = 1000001;
    int push_count = 1;

    for (int i = 1; i <= N; i++) {
        int cur;
        cin >> cur;

        if (prev <= cur) {
            push_count += 1;
        }

        prev = cur;
    }

    cout << push_count;
}