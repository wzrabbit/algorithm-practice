#include <iostream>
using namespace std;

int before[500001];
int after[500001];
int temp[500001];
int diff = 0;
bool success = false;

void merge(int start, int end)
{
    int mid = (start + end) / 2;
    int l = start;
    int r = mid + 1;
    int i = start;

    while (l <= mid && r <= end)
    {
        if (before[l] <= before[r])
        {
            temp[i] = before[l];
            l++;
        }
        else
        {
            temp[i] = before[r];
            r++;
        }
        i++;
    }

    if (l <= mid)
    {
        while (l <= mid)
        {
            temp[i] = before[l];
            l++;
            i++;
        }
    }

    if (r <= end)
    {
        while (r <= end)
        {
            temp[i] = before[r];
            r++;
            i++;
        }
    }

    for (int i = start; i <= end; i++)
    {
        if (before[i] == after[i])
            diff++;

        before[i] = temp[i];

        if (before[i] == after[i])
            diff--;

        if (diff == 0)
        {
            success = true;
            break;
        }
    }
}

void merge_sort(int start, int end)
{
    if (start < end)
    {
        if (success)
            return;

        int mid = (start + end) / 2;
        merge_sort(start, mid);
        merge_sort(mid + 1, end);
        merge(start, end);
    }
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    int N;
    cin >> N;

    for (int i = 0; i < N; i++)
        cin >> before[i];

    for (int i = 0; i < N; i++)
        cin >> after[i];

    for (int i = 0; i < N; i++)
    {
        if (before[i] != after[i])
            diff++;
    }

    if (diff > 0)
        merge_sort(0, N - 1);
    else
        success = true;

    if (success)
        cout << 1;
    else
        cout << 0;
}