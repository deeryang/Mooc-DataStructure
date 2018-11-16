#include <stdio.h>

#define MaxTree 10
#define ElementType char
#define Tree int
//#define Null -1

struct TreeNode {
    char element;
    int left;
    int right;
};

struct TreeNode T1[MaxTree];
struct TreeNode T2[MaxTree];

int buildTree(struct TreeNode T[])
{
    int N, i;
    int Root = -1;
    char cl, cr;
    scanf("%d\n", &N);
    int *check = new int[N];
    if (N)
    {
        for (i = 0; i < N; i ++)
        {
            scanf("%c %c %c\n", &T[i].element, &cl, &cr);
            check[i] = 0;
            if (cl != '-')
            {
                T[i].left = cl - '0';
                check[T[i].left] = 1;
            }
            else
            {
                T[i].left = -1;
            }

            if (cr != '-')
            {
                T[i].right = cr - '0';
                check[T[i].right] = 1;
            }
            else
            {
                T[i].right = -1;
            }
        }
        for (i = 0; i < N; i ++)
        {
            if (!check[i])
                break;
        }
        Root = i;
    }

    return Root;
}

int isomorphic(int R1, int R2)
{
    if ((R1 == -1) && (R2 == -1))
        return 1;
    if ( ((R1 == -1) && (R2 != -1)) || ((R1 != -1) && (R2 == -1)) )
        return 0;
    if (T1[R1].element != T2[R2].element)
        return 0;
    if ( (T1[R1].left == -1) && (T2[R2].left == -1) )
        return isomorphic(T1[R1].right, T2[R2].right);
    if ( ((T1[R1].left != -1) && (T2[R2].left != -1)) &&
         T1[T1[R1].left].element == T2[T2[R2].left].element)
        return (isomorphic(T1[R1].left, T2[R2].left) &&
                isomorphic(T1[R1].right, T2[R2].right));
    else
        return (isomorphic(T1[R1].left, T2[R2].right) &&
                isomorphic(T1[R1].right, T2[R2].left));
}

int main()
{
    int R1, R2;
    R1 = buildTree(T1);
    R2 = buildTree(T2);

    if (isomorphic(R1, R2))
        printf("Yes\n");
    else
        printf("No\n");

    return 0;
}
