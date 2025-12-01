#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int arr[5];
vector<vector<int>> queries;
int N;

vector<vector<int>> should_change_list = {
    {1, 2, 3, 4}, {1, 3, 2, 4}, {1, 4, 2, 3}, {2, 3, 1, 4}, {2, 4, 1, 3},
    {3, 1, 4, 2}, {3, 2, 4, 1}, {4, 1, 3, 2}, {4, 2, 3, 1}, {4, 3, 2, 1}};

int get_exact_index(int index) {
    if (index == 3 && N == 3) return 3;
    if (index == 3) return N - 1;
    if (index == 4) return N;
    return index;
}

void perform_swap(int a) {
    queries.push_back({1, get_exact_index(a)});
    swap(arr[a], arr[a + 1]);
}

void perform_change(int a, int b) {
    queries.push_back({2, get_exact_index(a), get_exact_index(b)});
    for (int i = a; i <= b; i++) {
        if (arr[i] < min(arr[a], arr[b])) arr[i] = max(arr[a], arr[b]);
        if (arr[i] > max(arr[a], arr[b])) arr[i] = min(arr[a], arr[b]);
    }
}

void input_values_and_compress() {
    for (int i = 1; i <= N; i++) {
        int cur;
        cin >> cur;

        if (i == 1) arr[1] = cur;
        if (i == 2 && N) arr[2] = cur;
        if (i == N - 1) arr[3] = cur;
        if (i == N) arr[4] = cur;
        if (i == 3 && N == 3) arr[3] = cur;
    }

    vector<int> compressed(5);

    for (int i = 1; i <= min(N, 4); i++) {
        int result = 1;

        for (int j = 1; j <= min(N, 4); j++) {
            if (arr[i] > arr[j]) result += 1;
        }

        compressed[i] = result;
    }

    for (int i = 1; i <= min(N, 4); i++) {
        arr[i] = compressed[i];
    }
}

void output_answer() {
    cout << queries.size() << '\n';

    for (vector<int>& query : queries) {
        for (int value : query) {
            cout << value << ' ';
        }
        cout << '\n';
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> N;

    input_values_and_compress();

    if (N == 3) {
        if (arr[2] == 2) perform_swap(1);
        perform_change(1, 3);

        if (arr[1] == arr[2]) {
            perform_swap(2);
        } else {
            perform_swap(1);
        }

        perform_change(1, 3);
        output_answer();
        return 0;
    }

    for (int i = 0; i < 10; i++) {
        bool same = true;

        for (int j = 1; j <= 4; j++) {
            if (arr[j] != should_change_list[i][j - 1]) {
                same = false;
                break;
            }
        }

        if (same) {
            perform_swap(1);
            break;
        }
    }

    perform_change(1, 4);

    if (arr[1] == arr[3]) {
        perform_swap(3);
    } else {
        perform_swap(1);
    }

    perform_change(1, 4);
    output_answer();
}
