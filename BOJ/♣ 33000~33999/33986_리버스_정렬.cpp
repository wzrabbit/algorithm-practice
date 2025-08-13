#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int arr[5001];
vector<pair<int, int>> answer;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N;
    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
    }

    int wrong_pos_count = 0;
    bool found_wrong_pos = true;

    while (found_wrong_pos) {
        found_wrong_pos = false;

        for (int i = wrong_pos_count + 1; i <= N; i += 2) {
            if (arr[i] % 2 != i % 2) {
                found_wrong_pos = true;
                wrong_pos_count += 1;

                if (wrong_pos_count != i) {
                    answer.push_back(make_pair(wrong_pos_count, i));
                    reverse(arr + wrong_pos_count, arr + i + 1);
                }

                break;
            }
        }
    }

    if (wrong_pos_count >= 2) {
        answer.push_back(make_pair(1, wrong_pos_count));
        reverse(arr + 1, arr + wrong_pos_count + 1);
    }

    for (int i = 1; i <= N - 1; i++) {
        for (int j = i + 1; j <= N; j++) {
            if (arr[j] == i) {
                answer.push_back(make_pair(i, j));
                reverse(arr + i, arr + j + 1);
                break;
            }
        }
    }

    cout << answer.size() << '\n';

    for (pair<int, int> cur : answer) {
        cout << cur.first << ' ' << cur.second << '\n';
    }
}
