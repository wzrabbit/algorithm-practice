#include <algorithm>
#include <iostream>
using namespace std;

int grid[401][401];
int left_prefix[401][401];
int right_prefix[401][401];

int get_sum(int start_R, int start_C, int scale) {
    int end_R = start_R + scale - 1;
    int end_C = start_C + scale - 1;
    int result = 0;
    result += right_prefix[end_R][end_C] - right_prefix[start_R - 1][start_C - 1];
    result -= left_prefix[end_R][start_C] - left_prefix[start_R - 1][end_C + 1];
    return result;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N;
    cin >> N;

    for (int r = 1; r <= N; r++) {
        for (int c = 1; c <= N; c++) {
            cin >> grid[r][c];
        }
    }

    for (int r = 1; r <= N; r++) {
        for (int c = 1; c <= N; c++) {
            right_prefix[r][c] = right_prefix[r - 1][c - 1] + grid[r][c];
        }
    }

    for (int r = 1; r <= N; r++) {
        for (int c = N; c >= 1; c--) {
            left_prefix[r][c] = left_prefix[r - 1][c + 1] + grid[r][c];
        }
    }

    int answer = 0;
    for (int r = 1; r <= N; r++) {
        for (int c = 1; c <= N; c++) {
            for (int s = 1; max(r, c) + s - 1 <= N; s++) {
                answer = max(answer, get_sum(r, c, s));
            }
        }
    }

    cout << answer;
}