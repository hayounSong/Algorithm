#include <iostream>
using namespace std;

int binary_search(int a[], int start, int end, int m)
{
    int half = (start + end) / 2;

    if (m == a[half])
    {
        return half;
    }
    else if (start >= end)
    {
        return -1;
    }
    else if (m > a[half])
    {
        return binary_search(a, half + 1, end, m);
    }
    else
    {
        return binary_search(a, start, half, m);
    }
}
int main()
{

    int N;
    cin >> N;
    int n, m;
    for (int i = 0; i < N; i++)
    {
        cin >> n;
        cin >> m;

        int a[n + 1];

        for (int b = 0; b < n; b++)
        {
            cin >> a[b];
        }
        cout << binary_search(a, 0, n - 1, m) << "\n";
    }
}