#include <iostream>

using namespace std;

void swap(char *a, char *b)
{

    char temp = *a;
    *a = *b;
    *b = temp;
}

void str_reverse(char *str, int start, int end)
{

    if (start >= end)
    {

        cout << str << "\n";
    }
    else
    {
        swap(str[start], str[end]);
        str_reverse(str, start + 1, end - 1);
    }
}
int main()
{

    int n;

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        char c[100];

        cin >> c;
        int len = 0;
        for (int a = 0; c[a]; a++)
        {
            len++;
        }

        str_reverse(c, 0, len - 1);
    }
}