#include <iostream>

using namespace std;

int countc = 0;

struct stack
{
    int arr[1000];
    int last = -1;
    void init()
    {
        last = -1;
    }
    void push(int data)
    {
        last = last + 1;
        arr[last] = data;
        cout << arr[last] << " ";
    }
    void pop()
    {
        last = last - 1;
        cout << arr[last] << " ";
    }
};

stack s;

void fibo(int n, int a, int b, int c)
{
    if (n > 0)
    {

        fibo(n - 1, a, c, b);

        if (a == 3)
        {
            if (s.last == 0)
            {
                s.last = s.last - 1;
                cout << 0 << " ";
            }
            else
            {

                s.pop();
            }
        }
        if (c == 3)
        {

            s.push(n);
        }
        fibo(n - 1, b, a, c);
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
        fibo(a, 1, 2, 3);
        cout << "\n";
        s.init();
    }
}
