#include <iostream>
using namespace std;

#define MAX(a, b) ((a) > (b) ? (a) : (b))
int recurmax(int a[], int min, int max)
{
    if (min >= max)
    {
        return a[min];
    }
    else
    {
        int half = (min + max) / 2;
        int left = recurmax(a, min, half);
        int right = recurmax(a, half + 1, max);
        return MAX(left, right);
    }
}

int main()
{
    int N;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        int a[101];
        int min;
        int max;
        int num;

        cin >> num;
        for (int b = 0; b < num; b++)
        {
            cin >> a[b];
        }

        cout << recurmax(a, 0, num - 1) << "\n";
    }
}