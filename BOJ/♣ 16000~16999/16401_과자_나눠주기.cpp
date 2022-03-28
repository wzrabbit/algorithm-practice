#include < iostream >
using namespace std;

int snacks[1000000];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int nephew, snack, s;
    cin >> nephew >> snack;
    for (int i = 0; i < snack; i++)
    {
        cin >> s;
        snacks[i] = s;
    }

    int start = 1;
    int end = 1000000000;
    int mid;
    bool success;

    while (start <= end)
    {
        success = false;
        mid = (start + end) / 2;
        int index = 0;
        int slice = 0;

        while (index < snack)
        {
            if (snacks[index] >= mid)
            {
                slice += snacks[index] / mid;
            }
            if (slice >= nephew)
            {
                success = true;
                break;
            }
            index++;
        }

        if (success)
            start = mid + 1;
        else
            end = mid - 1;
    }

    cout << end;
}