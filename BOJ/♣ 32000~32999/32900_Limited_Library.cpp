#include <algorithm>
#include <iostream>
using namespace std;

int S, B, book_limit, art_limit;
int shelves[100001];
int books[100001];

bool is_possible(int art_count) {
    int book_index = 1;

    for (int i = 1; i <= S; i++) {
        int capacity = (i >= S - art_count + 1) ? art_limit : book_limit;

        for (int j = 1; j <= capacity; j++) {
            if (book_index > B) return true;
            if (books[book_index] > shelves[i]) return false;
            book_index += 1;
        }
    }

    return book_index > B;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> S >> B >> book_limit >> art_limit;

    for (int i = 1; i <= S; i++) {
        cin >> shelves[i];
    }

    for (int i = 1; i <= B; i++) {
        cin >> books[i];
    }

    sort(shelves + 1, shelves + S + 1, greater<int>());
    sort(books + 1, books + B + 1, greater<int>());

    int start = 0;
    int end = S;
    int mid;

    while (start <= end) {
        mid = (start + end) / 2;

        if (is_possible(mid)) {
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }

    if (end == -1) {
        cout << "impossible";
    } else {
        cout << end;
    }
}
