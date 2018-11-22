#include <iostream>

using namespace std;

int getMaxSubseqSum(int a[], int n);
int divideAndConquer(int a[], int left, int right);

int main()
{
    int n;
    cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; i ++)
    {
        cin >> arr[i];
    }

//    int maxSum  = getMaxSubseqSum(arr, n);
    int maxSum = divideAndConquer(arr, 0, n-1);

    cout << maxSum << endl;

    delete[] arr;
    return 0;
}

// 在线处理，从左往右， 复杂度为O(1)
int getMaxSubseqSum(int a[],int n)
{
    int sum = 0;
    int maxSum = 0;
    for (int i = 0; i < n; i ++)
    {
        sum = sum + a[i];
        if (sum > maxSum)
        {
            maxSum = sum;
        }
        else if (sum < 0)
        {
            sum = 0;
        }
    }

    return maxSum;
}

// 分治算法，复杂度为O(nlogn)

int max3(int A, int B, int C)
{
    return A > B ? A > C ? A : C : B > C ? B : C;
}

int divideAndConquer(int a[], int left, int right)
{
    int maxLeftSum, maxRightSum;
    int maxLeftBorderSum, maxRightBorderSum;
    int leftBorderSum, rightBorderSum;
    int center;

    if (left == right)
    {
        if (a[left] >0)
            return a[left];
        else
            return 0;
    }

    center = (left + right) / 2;
    maxLeftSum = divideAndConquer(a, left, center);
    maxRightSum = divideAndConquer(a, center + 1, right);

    maxLeftBorderSum = 0;
    leftBorderSum = 0;
    for (int i = center; i >= left; i --)
    {
        leftBorderSum += a[i];
        if (leftBorderSum > maxLeftBorderSum)
            maxLeftBorderSum = leftBorderSum;
    }

    maxRightBorderSum = 0;
    rightBorderSum = 0;
    for (int i = center + 1; i <= right; i ++)
    {
        rightBorderSum += a[i];
        if (rightBorderSum > maxRightBorderSum)
            maxRightBorderSum = rightBorderSum;
    }

    return max3(maxLeftSum, maxRightSum, maxLeftBorderSum + maxRightBorderSum);
}

