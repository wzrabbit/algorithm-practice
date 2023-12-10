#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N;
    cin >> N;

    string before, after;
    cin >> before >> after;

    int push_count = 0;

    for (int i = 0; i < N; i++) {
        push_count += min(abs(before[i] - after[i]), 26 - abs(before[i] - after[i]));
    }

    cout << push_count;
}