#include <stdio.h>
#include <ctime>
#include <cmath>

clock_t start, stop;

double duration;
#define MAX 10  /* 多项式最大项数 */
#define MAXK 1e6

double f1(int n, double a[], double x);
double f2(int n, double a[], double x);

int main()
{
    double a[MAX];
    for (int i = 0; i < MAX; i ++)
        a[i] = (double)i;

    start = clock();
    for (int i = 0; i < MAXK; i ++)
    {
        f1(MAX, a, 1.1);
    }
    stop = clock();
    duration = (double)(stop - start)/CLK_TCK;
    printf("ticks1 = %f\n", (double)(stop - start));
    printf("duration2 = %6.2e\n", duration);

    start = clock();
    for (int i = 0; i < MAXK; i ++)
        f2(MAX, a, 1.1);
    stop = clock();
    duration = (double)(stop - start)/CLK_TCK;
    printf("ticks2 = %f\n", (double)(stop - start));
    printf("duration2 = %6.2e\n", duration);

    return 0;
}

double f1(int n, double a[], double x)
{
    double f = 0;
    for (int i = 0; i < n; i ++)
    {
        f += a[i]*pow(x, i);
    }
    return f;
}

double f2(int n, double a[], double x)
{
    double f = 0;
    for (int i = 0; i < n; i ++)
    {
        f *= a[n-i-1] + x;
    }
    return f;
}
