#include <iostream>
#include <algorithm>
using namespace std;

int cards[500000];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int card, c, query, q;
    cin >> card;
    for (int i = 0; i < card; i++)
    {
        cin >> c;
        cards[i] = c;
    }
    sort(cards, cards + card);

    cin >> query;
    for (int i = 0; i < query; i++)
    {
        cin >> q;
        int start = 0;
        int end = card - 1;
        int mid;
        bool success = false;

        while (start <= end)
        {
            mid = (start + end) / 2;
            if (cards[mid] < q)
                start = mid + 1;
            else if (cards[mid] > q)
                end = mid - 1;
            else
            {
                success = true;
                break;
            }
        }

        if (success)
            cout << "1 ";
        else
            cout << "0 ";
    }
}