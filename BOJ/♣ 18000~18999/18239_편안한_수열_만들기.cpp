#include <iostream>
using namespace std;

int main()
{
    int N, K;
    scanf("%d %d", &N, &K);

    if (N == 2)
    {
        printf("YES\n");
        for (int i = 0; i < 5; i++)
            printf("swap 1 2\n");
    }
    else if (N == 3)
    {
        printf("NO\n");
    }
    else if (K == 1)
    {
        printf("YES\n");
        printf("reverse 1 2\n");
        printf("reverse 2 %d\n", N);
        printf("reverse 2 %d\n", N - 1);
        printf("swap 1 2\n");
        printf("swap 1 2\n");
    }
    else if (K == N - 1)
    {
        printf("YES\n");
        printf("reverse %d %d\n", N - 1, N);
        printf("reverse 1 %d\n", N - 1);
        printf("reverse 2 %d\n", N - 1);
        printf("swap 1 2\n");
        printf("swap 1 2\n");
    }
    else
    {
        printf("YES\n");
        printf("reverse 1 %d\n", K);
        printf("reverse %d %d\n", K + 1, N);

        for (int i = 0; i < 3; i++)
            printf("reverse 1 %d\n", N);
    }
}