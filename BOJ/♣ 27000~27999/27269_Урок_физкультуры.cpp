#include <algorithm>
#include <iostream>
using namespace std;

struct Person {
    int g, h;
};

bool operator<(Person const& a, Person const& b) {
    if (a.g != b.g) {
        return a.g < b.g;
    }

    return a.h > b.h;
}

Person people[51];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N;
    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> people[i].g >> people[i].h;
    }

    sort(people + 1, people + N + 1);

    int maximum_gap = 0;

    for (int i = 2; i <= N; i++) {
        maximum_gap = max(maximum_gap, abs(people[i - 1].h - people[i].h));
    }

    cout << maximum_gap;
}