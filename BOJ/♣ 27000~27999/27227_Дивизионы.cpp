#include <iostream>
#include <string>
using namespace std;

bool is_div_available[4];
int rating;
string contests;

void set_div_available() {
    for (size_t i = 0; i < contests.size(); i++) {
        int contest_no = contests[i] - '0';
        is_div_available[contest_no] = true;
    }
}

int get_main_division() {
    if (0 <= rating && rating <= 1600) {
        return 3;
    }

    if (1601 <= rating && rating <= 1900) {
        return 2;
    }

    return 1;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> rating >> contests;

    set_div_available();
    int main_division = get_main_division();

    if (is_div_available[main_division]) {
        cout << main_division;
        return 0;
    }

    for (int i = 1; i <= 3; i++) {
        if (is_div_available[i]) {
            cout << i;

            if (main_division < i) {
                cout << '*';
            }

            cout << '\n';
        }
    }
}