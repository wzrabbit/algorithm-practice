#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);

    int num;
    cin >> num;
    vector<int> div;

    for (int i = 0; i < num; i++)
    {
        int d;
        cin >> d;
        div.push_back(d);
    }

    sort(div.begin(), div.end());

    cout << div[0] * div[div.size() - 1];
}