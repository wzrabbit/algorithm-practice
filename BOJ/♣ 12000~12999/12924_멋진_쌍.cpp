#include <iostream>
#include <set>
#include <string>
using namespace std;

int main()
{
    cin.tie()->sync_with_stdio(0);
    int start, end;
    int cnt = 0;
    cin >> start >> end;
    set<int> used;

    for (int i = start; i <= end; i++)
    {
        string num = to_string(i);
        used.clear();

        for (int j = 0; j < num.length(); j++)
        {
            num = num.back() + num.substr(0, num.length() - 1);
            int new_num = stoi(num);

            if (new_num > i && new_num <= end && used.find(new_num) == used.end())
            {
                used.insert(new_num);
                cnt++;
            }
        }
    }

    cout << cnt;
}