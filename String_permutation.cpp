#include <iostream>
using namespace std;

void swap(char *a, char *b)
{
    char tmp = *a;
    *a = *b;
    *b = tmp;
}
int numcount = 0;
void permutation(char *str, int begin, int end)
{

    int range = end - begin;
    if (end - begin == 1)
    {
        long long count = 0;
        for (int i = 0; i < end; i++)
        {
            if (i % 2 == 0)
            {
                count = count + (int(str[i]) - 97);
            }
            else
            {
                count = count - (int(str[i]) - 97);
            }
        }

        if (count > 0)
        {
            // cout << str << " " << count << "\n";
            numcount++;
        }
    }
    else
    {
        int i;
        for (i = 0; i < range; i++)
        {
            swap(str[begin], str[begin + i]);

            permutation(str, begin + 1, end);
            swap(str[begin], str[begin + i]);
        }
    }
}
int main()
{
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        numcount = 0;

        char c[10];

        cin >> c;
        int len = 0;
        for (int a = 0; c[a]; a++)
        {
            len++;
        }

        permutation(c, 0, len);

        cout << numcount << "\n";
    }
}