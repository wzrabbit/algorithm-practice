#include <iostream>
#include <algorithm>
#include <string>
#include <deque>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string before;
    deque<char> main_deque;
    deque<char> opposite_deque;
    string bomb;

    cin >> bomb;
    cin >> before;
    int l = 0;
    int r = before.length() - 1;
    while (l <= r) {
        bool baton = false;
        while (l <= r && baton == false) {
            main_deque.push_back(before[l]);
            l++;
            if (main_deque[main_deque.size() - 1] == bomb.back() && main_deque.size() >= bomb.length()) {
                int same = true;
                for (int i = 0; i <= bomb.length() - 1; i++) {
                    if (main_deque[main_deque.size() - bomb.length() + i] != bomb[i]) {
                        same = false;
                        break;
                    }
                }
                if (same) {
                    for (int i = 0; i <= bomb.length() - 1; i++) main_deque.pop_back();
                    baton = true;
                    break;
                }
            }
        }

        baton = false;
        while (l <= r && baton == false) {
            opposite_deque.push_front(before[r]);
            r--;
            if (opposite_deque[0] == bomb.front() && opposite_deque.size() >= bomb.length()) {
                int same = true;
                for (int i = 0; i <= bomb.length() - 1; i++) {
                    if (opposite_deque[i] != bomb[i]) {
                        same = false;
                        break;
                    }
                }
                if (same) {
                    for (int i = 0; i <= bomb.length() - 1; i++) opposite_deque.pop_front();
                    baton = true;
                    break;
                }
            }
        }
    }

    while (opposite_deque.size() > 0) {
        main_deque.push_back(opposite_deque.front());
        opposite_deque.pop_front();
        if (main_deque[main_deque.size() - 1] == bomb.back() && main_deque.size() >= bomb.length()) {
            int same = true;
            for (int i = 0; i <= bomb.length() - 1; i++) {
                if (main_deque[main_deque.size() - bomb.length() + i] != bomb[i]) {
                    same = false;
                    break;
                }
            }
            if (same) {
                for (int i = 0; i <= bomb.length() - 1; i++) main_deque.pop_back();
            }
        }
    }

    for (int i = 0; i < main_deque.size(); i++) cout << main_deque[i];
}