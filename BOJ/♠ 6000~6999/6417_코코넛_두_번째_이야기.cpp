#include <iostream>
#include <algorithm>
using namespace std;

bool test(int N, int P)
{
    for (int i = 0; i < P; i++)
    {
        N--;
        if (N < 0 || N % P != 0)
            return false;

        N = N / P * (P - 1);
    }

    if (N % P != 0)
        return false;
    else
        return true;
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    while (true)
    {
        int N;
        cin >> N;

        if (N == -1)
            break;

        int answer = -1;
        for (int i = 1000000; i >= 2; i--)
        {
            if (test(N, i))
            {
                answer = i;
                break;
            }
        }

        if (answer == -1)
            cout << N << " coconuts, no solution\n";
        else
            cout << N << " coconuts, " << answer << " people and 1 monkey\n";
    }
}