#include <iostream>
#include <string>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    string scream;
    cin >> scream;

    int A_count = 0;
    for (size_t i = 0; i < scream.size(); i++) {
        if (scream[i] == 'A') {
            A_count += 1;
        }
    }

    int problem_count = 0;
    int level = 1;
    while (true) {
        if (A_count < level) {
            break;
        }

        problem_count += 1;
        A_count -= level;
        level += 1;
    }

    cout << problem_count;
}