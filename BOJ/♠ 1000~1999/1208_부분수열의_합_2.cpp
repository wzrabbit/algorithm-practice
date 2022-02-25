#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;

int raw[41];
int arr_A[1048577];
int arr_B[1048577];
int fill_count;

void fill_array(int current, int end, int value, int using_arr[], int save_arr[])
{
    if (current > end)
    {
        save_arr[fill_count] = value;
        fill_count++;
        return;
    }

    fill_array(current + 1, end, value, using_arr, save_arr);
    fill_array(current + 1, end, value + using_arr[current], using_arr, save_arr);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, s;
    cin >> n >> s;
    for (int i = 1; i <= n; i++)
        cin >> raw[i];

    if (n == 1)
    {
        if (raw[1] == s)
            cout << 1;
        else
            cout << 0;
        exit(0);
    }

    int arrA_size = 0, arrB_size = 0;
    fill_count = 0;
    fill_array(1, n / 2, 0, raw, arr_A);
    arrA_size = fill_count;
    fill_count = 0;
    fill_array(n / 2 + 1, n, 0, raw, arr_B);
    arrB_size = fill_count;
    ll answer = 0;
    sort(arr_A + 1, arr_A + arrA_size + 1);
    sort(arr_B + 1, arr_B + arrB_size + 1);
    int pointer_A = 1;
    int pointer_B = arrB_size;

    while (pointer_A <= arrA_size && pointer_B >= 1)
    {
        int calc = arr_A[pointer_A] + arr_B[pointer_B];
        if (calc > s)
            pointer_B--;
        else if (calc < s)
            pointer_A++;
        else
        {
            ll A_count = 0, B_count = 0;
            int A_mem = arr_A[pointer_A];
            int B_mem = arr_B[pointer_B];
            while (pointer_A <= arrA_size && arr_A[pointer_A] == A_mem)
            {
                A_count++;
                pointer_A++;
            }
            while (pointer_B >= 1 && arr_B[pointer_B] == B_mem)
            {
                B_count++;
                pointer_B--;
            }
            answer += A_count * B_count;
        }
    }

    if (s == 0)
        answer--;
    cout << answer;
}