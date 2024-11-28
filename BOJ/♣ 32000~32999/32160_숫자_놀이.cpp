#include <algorithm>
#include <iostream>
#include <set>
#include <vector>
using namespace std;

multiset<int, greater<int>> numbers;
vector<pair<int, int>> answer;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N;
    cin >> N;

    for (int i = 1; i <= N - 1; i++) {
        numbers.insert(i);
    }

    while (numbers.size() >= 2) {
        auto it = numbers.begin();
        int highest = *it;
        numbers.erase(it);

        it = numbers.begin();
        int second_highest = *it;
        numbers.erase(it);

        answer.push_back(make_pair(highest, second_highest));
        numbers.insert(highest - second_highest);
    }

    cout << N - *(numbers.begin()) << '\n';

    for (size_t i = 0; i < answer.size(); i++) {
        cout << answer[i].first << " " << answer[i].second << '\n';
    }

    cout << *(numbers.begin()) << ' ' << N;
}
