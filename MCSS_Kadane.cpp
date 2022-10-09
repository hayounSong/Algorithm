#include <iostream>

using namespace std;

void mcss(int a[], int n)
{

    int maxsum = 0;
    int thissum = 0;

    int start = -1;
    int end = -1;
    int i = 0;
    for (int j = 0; j < n; j++)
    {
        thissum = thissum + a[j];

        if (thissum > maxsum)
        {

            start = i;
            end = j;
            maxsum = thissum;
        }
        else if (thissum <= 0)
        {
            i = j + 1;
            thissum = 0;
        }
    }
    if (maxsum < 0)
    {
        maxsum = 0;
        start = -1;
        end = -1;
    }
    cout << maxsum << " " << start << " " << end;
}
int main()
{
    int N;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        int size;
        cin >> size;
        int a[size + 1];
        for (int b = 0; b < size; b++)
        {
            cin >> a[b];
        }
        mcss(a, size);
        cout << "\n";
    }
}