#include <stdio.h>
#include <iostream>

using namespace std;

void printN(int n)
{
    if (n)
    {
        printN(n - 1);
        printf("%d\n", n);
    }

}

void printN2(int n)
{
    for (int i = 0; i < n; i ++)
    {
        printf("%d\n", i+1);
    }
}

int main()
{
    int n;
    printf("please input the value of n : \n");
    cin >> n;
    printf("method 1 : \n");
    printN(n);
    printf("method 2 : \n");
    printN2(n);

    return 0;
}
