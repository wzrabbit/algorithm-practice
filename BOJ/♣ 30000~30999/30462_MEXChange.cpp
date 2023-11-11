#include <iostream>
#include <stack>
#include <string>
typedef long long ll;
using namespace std;

int mex[200001];
int mex_value_count[200001];
bool is_banned[200001];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N;
    cin >> N;

    for (int i = 1; i <= N; i++) {
        int cur;
        cin >> cur;

        mex[i] = cur - 1;
        mex_value_count[cur - 1] += 1;
    }

    for (int i = 1; i <= N - 1; i++) {
        if (mex[i] > i || mex[i] < mex[i - 1]) {
            cout << "No";
            return 0;
        }
    }

    if (mex[N] != N) {
        cout << "No";
        return 0;
    }

    cout << "Yes\n";

    int pointer = N - 1;
    stack<int> answer;

    for (int i = N - 1; i >= 0; i--) {
        if (is_banned[mex[i]]) {
            while (is_banned[pointer]) {
                pointer -= 1;
            }

            is_banned[pointer] = true;
            answer.push(pointer + 1);
        } else {
            is_banned[mex[i]] = true;
            answer.push(mex[i] + 1);
        }
    }

    while (!answer.empty()) {
        cout << answer.top() << ' ';
        answer.pop();
    }
}
