#include <iostream>

using namespace std;
#include <algorithm>
#include <stdio.h>
#define MAX_SIZE 1000
void bubbleSort(int a[], int n);
void bubbleSortImproved1(int a[], int n);
void bubbleSortImproved2(int a[], int n);
void copyArray(int a[], int b[], int n);
int main()
{
    int numTestCases;
    int a[MAX_SIZE], b[MAX_SIZE];
    scanf("%d", &numTestCases);
    for (int i = 0; i < numTestCases; ++i)
    {
        int num;
        scanf("%d", &num);
        for (int j = 0; j < num; j++)
            scanf("%d", &b[j]);
        copyArray(a, b, num);
        bubbleSort(a, num);
        copyArray(a, b, num);
        bubbleSortImproved1(a, num);
        copyArray(a, b, num);
        bubbleSortImproved2(a, num);
        printf("\n");
    }
    return 0;
}
void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
/* BubbleSort 함수 */
void bubbleSort(int a[], int n)
{
    int countCmpOps = 0; // 비교 연산자 실행 횟수
    int countSwaps = 0;  // swap 함수 실행 횟수
    int temp = 0;
    for (int i = 0; i < n; i++)
    {

        for (int b = 0; b < n - i - 1; b++)
        {
            countCmpOps = countCmpOps + 1;
            if (a[b] > a[b + 1])
            {

                temp = a[b + 1];
                a[b + 1] = a[b];
                a[b] = temp;
                countSwaps = countSwaps + 1;
            }
        }
    };

    // bubble sort 알고리즘 구현
    printf("%d %d ", countCmpOps, countSwaps);
}

/* BubbleSort 함수 - Improved Version 1 */
void bubbleSortImproved1(int a[], int n)
{

    int countCmpOps = 0; // 비교 연산자 실행 횟수
    int countSwaps = 0;  // swap 함수 실행 횟수
    int temp = 0;
    // bubble sort의 개선된 알고리즘 (1) 구현
    for (int i = 0; i < n; i++)
    {
        int swap = 0;
        for (int b = 0; b < n - i - 1; b++)
        {
            countCmpOps = countCmpOps + 1;
            if (a[b] > a[b + 1])
            {

                temp = a[b + 1];
                a[b + 1] = a[b];
                a[b] = temp;
                countSwaps = countSwaps + 1;
                swap = 1;
            }
        }
        if (swap == 0)
        {
            break;
        }
    };
    printf("%d %d ", countCmpOps, countSwaps);
}
/* BubbleSort 함수 - Improved Version 2 */
void bubbleSortImproved2(int a[], int n)
{
    int countCmpOps = 0; // 비교 연산자 실행 횟수
    int countSwaps = 0;  // swap 함수 실행 횟수
    // bubble sort의 개선된 알고리즘 (2) 구현

    int lastswap = n;
    int swapset;
    int temp;
    while (lastswap > 0)
    {
        swapset = 0;
        for (int i = 0; i < lastswap - 1; i++)
        {
            countCmpOps++;
            if (a[i] > a[i + 1])
            {
                temp = a[i];
                a[i] = a[i + 1];
                a[i + 1] = temp;
                swapset = i + 1;
                countSwaps++;
            }
        }
        lastswap = swapset;
    }

    printf("%d %d ", countCmpOps, countSwaps);
}
void copyArray(int a[], int b[], int n)
{
    for (int i = 0; i < n; i++)
        a[i] = b[i];
}