#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
typedef long long ll;
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    vector<ll> numbers;

    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;

        reverse(s.begin(), s.end());

        ll number = stoll(s);
        numbers.push_back(number);
    }

    sort(numbers.begin(), numbers.end());

    for (int i = 0; i < N; i++) {
        cout << numbers[i] << '\n';
    }
}
