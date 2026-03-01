#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

int main() {
    int N, start, end;
    cin >> N >> start >> end;

    string S;
    cin >> S;

    reverse(S.begin() + start - 1, S.begin() + end);

    cout << S;
}
