#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

int message[1001];
unordered_map<int, int> index;
unordered_map<int, int> frequency;

bool sorter(int a, int b) {
    if (frequency[a] != frequency[b]) return frequency[a] > frequency[b];
    return index[a] < index[b];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, d;
    cin >> n >> d;
    for (int i = 0; i < n; i++) {
        cin >> d;
        message[i] = d;

        if (index.find(d) == index.end()) {
            index[d] = i;
        }
        if (frequency.find(d) == frequency.end()) {
            frequency[d] = 1;
        }
        else {
            frequency[d]++;
        }
    }

    sort(message, message + n, sorter);
    for (int i = 0; i < n; i++) {
        cout << message[i] << ' ';
    }
}