#include <iostream>
#include <vector>
using namespace std;

int left_responses[1002];
int right_responses[1002];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N;
    cin >> N;

    for (int i = 1; i <= N; i++) {
        cout << "? " << 1 << ' ' << i << endl;
        cin >> left_responses[i];

        cout << "? " << i << ' ' << N << endl;
        cin >> right_responses[i];
    }

    vector<int> answer;

    for (int i = 1; i <= N; i++) {
        if (left_responses[i - 1] + 1 == left_responses[i] && right_responses[i + 1] + 1 == right_responses[i]) {
            answer.push_back(i);
        }
    }

    cout << "! " << answer.size() << ' ';

    for (size_t i = 0; i < answer.size(); i++) {
        cout << answer[i] << ' ';
    }

    cout << endl;
}
