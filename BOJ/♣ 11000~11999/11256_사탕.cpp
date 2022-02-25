#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);

    int test;
    cin >> test;

    for (int i = 0; i < test; i++)
    {
        int c, b;
        vector<int> box;
        cin >> c >> b;

        for (int j = 0; j < b; j++)
        {
            int w, h;
            cin >> w >> h;
            box.push_back(w * h);
        }

        sort(box.begin(), box.end(), greater<int>());

        int count = 0;
        for (int i = 0; i < box.size(); i++)
        {
            c -= box[i];
            count++;
            if (c <= 0)
                break;
        }

        cout << count << '\n';
    }
}