#include <algorithm>
#include <iostream>
#include <set>
#include <vector>
typedef long long ll;
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N;
    cin >> N;

    vector<int> ascending_lines, descending_lines;
    set<int> x_points;

    for (int i = 1; i <= N; i++) {
        int x, y;
        cin >> x >> y;

        ascending_lines.push_back(x - y);
        descending_lines.push_back(x + y);
        x_points.insert(x - y);
        x_points.insert(x + y);
    }

    sort(ascending_lines.begin(), ascending_lines.end());
    sort(descending_lines.begin(), descending_lines.end());

    ascending_lines.erase(
        unique(ascending_lines.begin(), ascending_lines.end()),
        ascending_lines.end());
    descending_lines.erase(
        unique(descending_lines.begin(), descending_lines.end()),
        descending_lines.end());

    ll answer = x_points.size();

    for (size_t i = 0; i < ascending_lines.size(); i++) {
        answer += descending_lines.end() - upper_bound(descending_lines.begin(),
                                                       descending_lines.end(),
                                                       ascending_lines[i]);
    }

    cout << answer;
}
