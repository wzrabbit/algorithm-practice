#include <iostream>
#include <map>
using namespace std;

map<int, int> horizontal_gap_count;
map<int, int> vertical_gap_count;
int horizontal_lines[1501];
int vertical_lines[1501];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int H, V;
    cin >> H >> V;

    for (int i = 1; i <= H; i++) {
        cin >> horizontal_lines[i];
    }

    for (int i = 1; i <= V; i++) {
        cin >> vertical_lines[i];
    }

    for (int i = 1; i <= H - 1; i++) {
        for (int j = i + 1; j <= H; j++) {
            vertical_gap_count[horizontal_lines[j] - horizontal_lines[i]] += 1;
        }
    }

    for (int i = 1; i <= V - 1; i++) {
        for (int j = i + 1; j <= V; j++) {
            horizontal_gap_count[vertical_lines[j] - vertical_lines[i]] += 1;
        }
    }

    int answer = 0;

    for (auto it = horizontal_gap_count.begin();
         it != horizontal_gap_count.end(); it++) {
        answer += vertical_gap_count[it->first] * it->second;
    }

    cout << answer;
}
