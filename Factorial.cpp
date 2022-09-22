#include <iostream>

using namespace std;

int factorial(int n)
{
    int sum;
    if (n == 0)
    {
        return 1;
    }
    else
    {
        sum = (n * factorial(n - 1));

        while (sum % 10 == 0)
        {
            sum = sum / 10;
        }

        return sum % 100000;
    }
}

int main()
{
    int n;
    int a;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        cout << factorial(a) % 1000;
        cout << "\n";
    }
}