#include <iostream>
using namespace std;
#define MAX_SIZE 1000
void insertionSort(int a[], int n);
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
        insertionSort(a, num);
    }
    return 0;
}
/* Insertion Sort 함수 */
void insertionSort(int a[], int n)
{
    int countCmpOps = 0; // 비교 연산자 실행 횟수
    int countSwaps = 0;  // swap 함수 실행 횟수
    // insertion sort 알고리즘 구현

    for (int i = 0; i < n - 1; i++)
    {

        int min = a[i];
        int mindex = i;
        for (int b = i + 1; b < n; b++)
        {
            countCmpOps++;
            if (a[b] < min)
            {
                min = a[b];
                mindex = b;
            }
        }
        if (mindex != i)
        {
            countSwaps++;
            swap(a[mindex], a[i]);
        }
    }
    // for (int i = 0; i < n; i++)
    // {
    //     cout << a[i];
    // }
    printf("%d %d ", countCmpOps, countSwaps);
    cout << "\n";
}