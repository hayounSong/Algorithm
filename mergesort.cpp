#include <iostream>
using namespace std;

int count_sum;
// void merge(int a[], int low, int mid, int high)
// {
//     int i, j, k;
//     int tmp[101];
//     for (i = low; i <= high; i++)
//         tmp[i] = a[i];
//     i = k = low;
//     j = mid + 1;
//     while (i <= mid && j <= high)
//         if (tmp[i] <= tmp[j])
//         { // <---- 핵심연산자(비교연산자)
//             count_sum++;
//             a[k++] = tmp[i++];
//         }
//         else
//         {
//             count_sum++;
//             a[k++] = tmp[j++];
//         }
//     while (i <= mid)
//         a[k++] = tmp[i++];
//     while (j <= high)
//         a[k++] = tmp[j++];
// }

void merge(int a[], int low, int mid, int high)
{

    int temp[101];
    for (int i = low; i <= high; i++)
    {
        temp[i] = a[i];
    }

    int left = low;
    int right = mid + 1;
    int id = low;
    while (left <= mid && right <= high)
    {
        if (temp[left] <= temp[right])
        {
            count_sum++;
            a[id] = temp[left];
            id++;
            left++;
        }
        else
        {
            count_sum++;
            a[id] = temp[right];
            id++;
            right++;
        }
    }

    while (left <= mid)
    {
        a[id] = temp[left];
        id++;
        left++;
    }
    while (right <= high)
    {
        a[id] = temp[right];
        id++;
        right++;
    }
}

void mergesort(int a[], int low, int high)
{
    int mid = (low + high) / 2;

    if (low >= high)
    {
    }
    else
    {
        mergesort(a, low, mid);
        mergesort(a, mid + 1, high);
        merge(a, low, mid, high);
    }
}

int main()
{
    int N;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        count_sum = 0;
        int size;
        cin >> size;
        int a[size + 1];
        for (int b = 0; b < size; b++)
        {
            cin >> a[b];
        }

        mergesort(a, 0, size - 1);
        // cout << count_sum;
        for (int b = 0; b < size; b++)
        {
            cout << a[b] << " ";
        }
        cout << "\n";
    }
}