#include <iostream>
using namespace std;

int arr[100001];
int inv[100001];

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    while (true)
    {
        int N;
        cin >> N;

        if (N == 0)
            break;

        for (int i = 1; i <= N; i++)
        {
            cin >> arr[i];
            inv[arr[i]] = i;
        }

        bool same = true;
        for (int i = 1; i <= N; i++)
        {
            if (arr[i] != inv[i])
            {
                same = false;
                break;
            }
        }

        if (same)
            cout << "ambiguous\n";
        else
            cout << "not ambiguous\n";
    }
}