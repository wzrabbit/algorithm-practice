#include <iostream>
using namespace std;

void print_top(int N)
{
    for (int r = 0; r < N; r++)
    {
        for (int c = 0; c < N * 3; c++)
            cout << '@';

        for (int c = N * 3; c < N * 4; c++)
            cout << ' ';

        for (int c = N * 4; c < N * 5; c++)
            cout << '@';

        cout << '\n';
    }
}

void print_mid(int N)
{
    for (int r = 0; r < N * 3; r++)
    {
        for (int c = 0; c < N; c++)
            cout << '@';

        for (int c = N; c < N * 2; c++)
            cout << ' ';

        for (int c = N * 2; c < N * 3; c++)
            cout << '@';

        for (int c = N * 3; c < N * 4; c++)
            cout << ' ';

        for (int c = N * 4; c < N * 5; c++)
            cout << '@';

        cout << '\n';
    }
}

void print_bottom(int N)
{
    for (int r = 0; r < N; r++)
    {
        for (int c = 0; c < N; c++)
            cout << '@';

        for (int c = N; c < N * 2; c++)
            cout << ' ';

        for (int c = N * 2; c < N * 5; c++)
            cout << '@';

        cout << '\n';
    }
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    int N;
    cin >> N;

    print_top(N);
    print_mid(N);
    print_bottom(N);
}