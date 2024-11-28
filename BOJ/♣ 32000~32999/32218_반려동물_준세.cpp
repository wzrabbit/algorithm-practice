#include <iostream>
using namespace std;

int arr[201];
int next_arr[201];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N;
    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
    }

    int execute_count = 0;

    while (true) {
        execute_count += 1;

        for (int i = 1; i <= N; i++) {
            int big_count = 0;

            for (int j = i + 1; j <= N; j++) {
                if (arr[i] < arr[j]) {
                    big_count += 1;
                }
            }

            next_arr[i] = big_count;
        }

        bool is_all_same = true;

        for (int i = 1; i <= N; i++) {
            if (arr[i] != next_arr[i]) {
                is_all_same = false;
                break;
            }
        }

        if (is_all_same) {
            break;
        }

        for (int i = 1; i <= N; i++) {
            arr[i] = next_arr[i];
        }
    }

    cout << execute_count;
}
