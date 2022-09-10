#include <iostream>

using namespace std;
#include <math.h>
#include <stdio.h>
#define MAX_SIZE 1000
void combSort(int a[], int n);
int main()
{
    int numTestCases;
    scanf("%d", &numTestCases);
    for (int i = 0; i < numTestCases; ++i)
    {
        int num;
        int a[MAX_SIZE];
        scanf("%d", &num);
        for (int j = 0; j < num; j++)
            scanf("%d", &a[j]);
        combSort(a, num);
    }
    return 0;
}
void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
/* comb sort 함수 */
void combSort(int a[], int n)
{
    int countCmpOps = 0;
    int countSwaps = 0; // swap 함수 실행 횟수
    // comb sort 알고리즘 구현

    int gap = n;
    int sorted = 0;
    while (sorted != 1)
    {
        gap = floor(gap / 1.3);
        sorted = 0;

        if (gap <= 1)
        {
            gap = 1;
            sorted = 1;
        }
        for (int i = 0; i < n - gap; i++)
        {
            countCmpOps = countCmpOps + 1;
            if (a[i] > a[i + gap])
            {
                swap(a[i], a[i + gap]);
                sorted = 0;
                countSwaps = countSwaps + 1;
            }
        }
    }

    // for (int i = 0; i < n; i++)
    // {
    //     cout << a[i];
    // }

    printf("%d %d ", countCmpOps, countSwaps);
    cout << "\n";
}