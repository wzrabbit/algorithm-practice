#include <iostream>
#include <algorithm>
#include <cmath>
#include <iomanip>
using namespace std;

int paper[29];

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    int N;
    cin >> N;
    N--;

    for (int i = 0; i < N; i++)
        cin >> paper[i];

    double tape = 0.0;
    double line_length = pow(2, -0.75);
    int cell = 1; // 더 나누어져서 선 길이를 늘리는 데 기여할 cell개수

    for (int i = 0; i < N; i++)
    {
        tape += line_length * cell;
        cell *= 2;
        cell -= paper[i];
        line_length /= sqrt(2);

        if (cell <= 0)
            break;
    }

    if (cell <= 0)
    {
        cout << fixed;
        cout.precision(6);
        cout << tape;
    }
    else
        cout << "impossible";
}