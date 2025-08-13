#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

vector<int> left_heights;
vector<int> right_heights;
char directions[5002];
int board[5002];
int N;

int get_result(int mid) {
    int left_index = 0;
    int right_index = 0;
    int result = 0;

    if (directions[mid] == 'L') {
        board[mid] = left_heights[0];
        left_index += 1;
    } else {
        board[mid] = right_heights[0];
        right_index += 1;
    }

    for (int i = mid - 1; i >= 1; i--) {
        if (directions[i] == 'L') {
            board[i] = left_heights[left_index];
            left_index += 1;
        }
    }

    for (int i = mid + 1; i <= N; i++) {
        if (directions[i] == 'R') {
            board[i] = right_heights[right_index];
            right_index += 1;
        }
    }

    for (int i = mid + 1; i <= N; i++) {
        if (directions[i] == 'L') {
            board[i] = left_heights[left_index];
            left_index += 1;
        }
    }

    for (int i = mid - 1; i >= 1; i--) {
        if (directions[i] == 'R') {
            board[i] = right_heights[right_index];
            right_index += 1;
        }
    }

    int max_height = 0;

    for (int i = 1; i <= N; i++) {
        if (directions[i] == 'L' && board[i] > max_height) {
            result += 1;
        }

        max_height = max(max_height, board[i]);
    }

    max_height = 0;

    for (int i = N; i >= 1; i--) {
        if (directions[i] == 'R' && board[i] > max_height) {
            result += 1;
        }

        max_height = max(max_height, board[i]);
    }

    return result;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> N;

    for (int i = 1; i <= N; i++) {
        int height;
        char direction;
        cin >> height >> direction;

        if (direction == 'L') {
            left_heights.push_back(height);
        } else {
            right_heights.push_back(height);
        }

        directions[i] = direction;
    }

    sort(left_heights.begin(), left_heights.end(), greater<int>());
    sort(right_heights.begin(), right_heights.end(), greater<int>());

    int answer = 0;

    for (int i = 1; i <= N; i++) {
        answer = max(get_result(i), answer);
    }

    cout << answer;
}
