#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int n;
    cin >> n;
    char s;
    cin >> s;

    int size = floor(sqrt((n + 1)/2)) * 2 - 1;
    int leftNum =   n - 2*pow((size + 1)/2, 2) + 1;

    for (int i = 0; i < size; i ++)
    {
        for (int j = 0; j < size; j ++)
        {
            if (i < size / 2 + 1)
            {
                if (j < i || j > size - i - 1)
                    cout << " ";
                else
                    cout << s;
            }
            else
            {
                if (j < size - i - 1 || j > i)
                    cout << " ";
                else
                    cout << s;
            }

        }
        cout << endl;
    }

    cout << leftNum << endl;

    return 0;
}
