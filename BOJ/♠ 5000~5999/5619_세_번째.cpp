#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int element_count[10001];
vector<int> selected_numbers;
vector<int> produced_numbers;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N;
    cin >> N;

    for (int i = 1; i <= N; i++) {
        int cur;
        cin >> cur;

        element_count[cur] += 1;
    }

    int number_left_count = 4;

    for (int i = 1; i <= 10000; i++) {
        while (number_left_count > 0 && element_count[i] > 0) {
            number_left_count -= 1;
            element_count[i] -= 1;
            selected_numbers.push_back(i);
        }
    }

    for (size_t i = 0; i < selected_numbers.size(); i++) {
        for (size_t j = 0; j < selected_numbers.size(); j++) {
            if (i == j) {
                continue;
            }

            int merged_number = stoi(
                to_string(selected_numbers[i]) +
                to_string(selected_numbers[j]));

            produced_numbers.push_back(merged_number);
        }
    }

    sort(produced_numbers.begin(), produced_numbers.end());

    cout << produced_numbers[2];
}
