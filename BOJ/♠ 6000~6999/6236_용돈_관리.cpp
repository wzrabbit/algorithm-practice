#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(0);

    int data, limit;
    cin >> data >> limit;
    vector<int> need;

    for (int i = 0; i < data; i++) {
        int n;
        cin >> n;
        need.push_back(n);
    }

    int start = *max_element(need.begin(), need.end());
    int end = *max_element(need.begin(), need.end()) * need.size();
 
    while (start <= end) {
        int mid = (start + end) / 2;
        int money = mid;
        int count = 1;
        
        for (int i = 0; i < need.size(); i++) {
            if (money - need[i] < 0) {
                count++;
                money = mid - need[i];
            }
            else money -= need[i];
        }

        if (count > limit) start = mid + 1;
        else end = mid - 1;
    }

    cout << start;
}