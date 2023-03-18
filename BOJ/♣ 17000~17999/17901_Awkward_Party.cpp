#include <algorithm>
#include <iostream>
#include <map>
using namespace std;

map<int, int> gaps;
int minimum_gap;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N;
    cin >> N;

    minimum_gap = N;

    for (int i = 1; i <= N; i++) {
        int current_no;
        cin >> current_no;

        if (gaps.find(current_no) == gaps.end()) {
            gaps[current_no] = i;
        } else {
            minimum_gap = min(minimum_gap, i - gaps[current_no]);
            gaps[current_no] = i;
        }
    }

    cout << minimum_gap;
}