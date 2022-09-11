#include <iostream>
using namespace std;
#define MAX_SIZE 1000
void ShellSort(int a[], int n);
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
        ShellSort(a, num);
    }
    return 0;
}
void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
/* Shell Sort 함수 */
void ShellSort(int a[], int n)
{
    int countCmpOps = 0; // 비교 연산자 실행 횟수
    int countSwaps = 0;  // swap 함수 실행 횟수

    int gap = n;
    int shrink = 2;
    gap = n / 2;
    int j;
    while (gap > 0)
    {
        for (int i = gap; i < n; i++)
        {

            int temp = a[i];
            for (j = i; j >= gap; j -= gap)
            {

                if (a[j - gap] < temp)
                {
                    countCmpOps++;
                    break;
                }
                countCmpOps++;
                if (a[j - gap] > temp)
                {
                    a[j] = a[j - gap];
                    countSwaps++;
                }
            }
            a[j] = temp;
        }
        gap = gap / shrink;
    }

    // for (int i = 0; i < n; i++)
    // {
    //     cout << a[i];
    // }
    //
    // Shell sort 알고리즘 구현
    printf("%d %d ", countCmpOps, countSwaps);
    cout << "\n";
}