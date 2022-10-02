#include <iostream>

using namespace std;

struct matrix
{
    unsigned long long list[2][2];
};

matrix fibosum(struct matrix g, struct matrix x)
{

    struct matrix a;

    a.list[0][0] = (g.list[0][0] * x.list[0][0]) % 1000 + (g.list[0][1] * x.list[1][0]) % 1000;
    a.list[0][1] = (g.list[0][0] * x.list[0][1]) % 1000 + (g.list[0][1] * x.list[1][1]) % 1000;
    a.list[1][0] = (g.list[1][0] * x.list[0][0]) % 1000 + (g.list[1][1] * x.list[1][0]) % 1000;
    a.list[1][1] = (g.list[1][0] * x.list[0][1]) % 1000 + (g.list[1][1] * x.list[1][1]) % 1000;

    return a;
}

matrix fibo(int n)
{

    if (n == 1)
    {
        struct matrix a;
        a.list[0][0] = 1;
        a.list[0][1] = 1;
        a.list[1][0] = 1;
        a.list[1][1] = 0;
        return a;
    }
    else
    {
        if (n % 2 == 0)
        {
            struct matrix a = fibo(n / 2);
            return fibosum(a, a);
        }
        if (n % 2 == 1)
        {
            struct matrix a = fibo(n / 2);
            struct matrix b = fibosum(a, a);
            struct matrix c;
            c.list[0][0] = 1;
            c.list[0][1] = 1;
            c.list[1][0] = 1;
            c.list[1][1] = 0;
            return fibosum(c, b);
        }
    }
}

int main()
{

    int N;

    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int a;
        cin >> a;
        if (a == 0)
        {
            cout << 0 << "\n";
            continue;
        }
        cout << fibo(a).list[0][1] % 1000 << "\n";
    }
    // fibosum(29);

    // cout << list[0][0] % 1000;
}
