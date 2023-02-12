#include <algorithm>
#include <iostream>
#include <stack>
typedef long long ll;
using namespace std;

ll numbers[100002];
ll prefix[100002];
stack<int> indexes;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N;
    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> numbers[i];
    }
    numbers[0] = -1;

    for (int i = 1; i <= N + 1; i++) {
        prefix[i] = prefix[i - 1] + numbers[i];
    }

    ll max_value = 0;
    ll total_sum = 0;
    indexes.push(0);

    for (int i = 1; i <= N + 1; i++) {
        while (numbers[i] <= numbers[indexes.top()]) {
            int popped_index = indexes.top();
            indexes.pop();

            max_value = max(max_value, (prefix[i - 1] - prefix[indexes.top()]) * numbers[popped_index]);
        }

        indexes.push(i);
    }

    cout << max_value;
}