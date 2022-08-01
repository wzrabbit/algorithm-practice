#include <iostream>
using namespace std;

void print_A(int N)
{
    for (int r = 0; r < N * 4; r++)
    {
        for (int c = 0; c < N; c++)
            cout << '@';
        cout << '\n';
    }
}

void print_B(int N)
{
    for (int r = 0; r < N; r++)
    {
        for (int c = 0; c < N * 5; c++)
            cout << '@';
        cout << '\n';
    }
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    int N;
    cin >> N;

    print_A(N);
    print_B(N);
}