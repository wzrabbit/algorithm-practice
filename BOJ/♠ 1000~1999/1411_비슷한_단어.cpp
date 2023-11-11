#include <algorithm>
#include <iostream>
#include <string>
#define EMPTY 99
using namespace std;

string words[101];
int N;

bool is_pair(string A, string B) {
    char left_partners[27];
    char right_partners[27];
    fill(left_partners, left_partners + 26, '*');
    fill(right_partners, right_partners + 26, '*');

    for (size_t i = 0; i < A.size(); i++) {
        int left_index = A[i] - 'a';
        int right_index = B[i] - 'a';

        if (left_partners[left_index] != '*') {
            if (left_partners[left_index] == B[i]) {
                left_partners[left_index] = B[i];
            } else {
                return false;
            }
        } else {
            left_partners[left_index] = B[i];
        }

        if (right_partners[right_index] != '*') {
            if (right_partners[right_index] == A[i]) {
                right_partners[right_index] = A[i];
            } else {
                return false;
            }
        } else {
            right_partners[right_index] = A[i];
        }
    }

    return true;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> words[i];
    }

    int valid_pair_count = 0;

    for (int i = 1; i <= N - 1; i++) {
        for (int j = i + 1; j <= N; j++) {
            if (is_pair(words[i], words[j])) {
                valid_pair_count += 1;
            }
        }
    }

    cout << valid_pair_count;
}