#include <algorithm>
#include <iostream>
#include <map>
using namespace std;

int arr[100000];
int sorted_arr[100000];
bool visited[100000];
map<int, int> db;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        arr[i] = x;
        sorted_arr[i] = x;
    }

    sort(sorted_arr, sorted_arr + N);

    for (int i = 0; i < N; i++) {
        db[sorted_arr[i]] = i;
    }

    for (int i = 0; i < N; i++) {
        arr[i] = db[arr[i]];
    }

    int cnt = 0;
    for (int i = 0; i < N; i++) {
        if (visited[i]) continue;
        for (int j = i; !visited[j]; j = arr[j]) {
            visited[j] = true;
            cnt++;
        }
        cnt--;
    }

    cout << cnt;
}