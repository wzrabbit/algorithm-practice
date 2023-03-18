#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

bool is_int(string text) {
    for (size_t i = 0; i < text.size(); i++) {
        if (text[i] < '0' || text[i] > '9') {
            return false;
        }
    }

    return true;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int width = 1;
    int max_value = 0;
    string current_value;

    while (true) {
        cout << "? 1 " << width << endl;
        cin >> current_value;

        if (is_int(current_value)) {
            max_value = max(stoi(current_value), max_value);
            width += 1;
        } else {
            width -= 1;
            break;
        }
    }

    for (int r = 2; r <= width; r++) {
        for (int c = 1; c <= width; c++) {
            cout << "? " << r << ' ' << c << endl;
            cin >> current_value;
            max_value = max(stoi(current_value), max_value);
        }
    }

    cout << "! " << max_value << endl;
}