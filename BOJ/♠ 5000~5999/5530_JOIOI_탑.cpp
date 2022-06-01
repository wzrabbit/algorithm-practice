#include <iostream>
#include <vector>
using namespace std;

char joi_sample[1000001];
char joi[1000001];
int n;

bool is_possible(int num)
{
    for (int i = 0; i < n; i++)
        joi[i] = joi_sample[i];
    int left = num;

    for (int i = n - 1; i >= 0; i--)
    {
        if (left == 0)
            break;

        if (joi[i] == 'I')
        {
            joi[i] = 'E';
            left--;
        }
    }

    vector<int> a, b, c;
    for (int i = 0; i < n; i++)
    {
        if (joi[i] == 'E')
            c.push_back(i);
        else if (joi[i] == 'O')
            b.push_back(i);
        else
            a.push_back(i);
    }

    while (true)
    {
        if (c.size() == 0)
            return true;

        if (a.size() == 0 || b.size() == 0)
            return false;

        if (b.back() > c.back())
        {
            b.pop_back();
            continue;
        }

        if (a.back() > b.back())
        {
            a.pop_back();
            continue;
        }

        c.pop_back();
        b.pop_back();
        a.pop_back();
    }
}

int main()
{
    cin.tie()->sync_with_stdio(0);

    cin >> n;
    cin >> joi_sample;

    int start = 0;
    int end = 0;
    for (int i = 0; i < n; i++)
    {
        if (joi_sample[i] == 'I')
            end++;
    }

    int mid;
    while (start <= end)
    {
        mid = (start + end) / 2;

        if (is_possible(mid))
            start = mid + 1;
        else
            end = mid - 1;
    }

    cout << end;
}