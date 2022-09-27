#include <iostream>

using namespace std;

int main()
{

    int N;
    int A;
    cin >> N;
    for (int a = 0; a < N; a++)
    {
        int num[101];

        cin >> A;
        int count = 0;
        int sum = 1;
        int twocount = 0;
        int fivecount = 0;
        for (int i = 0; i < A; i++)
        {

            cin >> num[i];

            int imsi = sum;
            while (num[i] % 10 == 0)
            {

                num[i] = num[i] / 10;
                count++;
            }
            while (num[i] % 2 == 0)
            {

                twocount++;
                num[i] = num[i] / 2;
            }
            while (num[i] % 5 == 0)
            {

                fivecount++;
                num[i] = num[i] / 5;
            }

            num[i] = num[i] % 10;
            sum = sum * num[i];
            sum = sum % 10;
            while (fivecount > 0 && twocount > 0)
            {
                twocount--;
                fivecount--;
                count++;
            }
        }

               while (twocount > 0)
        {
            sum = sum * 2;
            twocount--;
            sum = sum % 10;
        }
        while (fivecount > 0)
        {
            sum = sum * 5;
            fivecount--;
            sum = sum % 10;
        }
        sum = sum % 10;

        cout << sum << " ";
        cout << count;
        cout << "\n";
    }
}
