#include <iostream>
#include <malloc.h>

using namespace std;

typedef struct TreeNode* Tree;
struct TreeNode {
    int v;
    Tree left;
    Tree right;
    int flag;
};

Tree newTreeNode(int V)
{
    Tree T = (Tree)malloc(sizeof(struct TreeNode));
    T->v = V;
    T->left = NULL;
    T->right = NULL;
    T->flag = 0;
    return T;
}

Tree insert(Tree T, int V)
{
    if (!T)
        T = newTreeNode(V);
    else
    {
        if (V > T->v)
            T->right = insert(T, V);
        else
            T->left = insert(T, V);
    }
    return T;
}

Tree makeTree(int N)
{
    Tree T;
    int v;

    cin >> v;
    T = newTreeNode(v);
    for (int i = 1; i < N; i ++)
    {
        cin >> v;
        T = insert(T, v);
    }
    return T;
}

int check(Tree T, int V)
{
    if (T->flag)
    {
        if (V < T->v)
            return check(T->left, V);
        else if (V > T->v)
            return check(T->right, V);
        else
            return 0;
    }
    else
    {
        if (V == T->v)
        {
            T->flag = 1;
            return 1;
        }
        else
            return 0;
    }
}

int judge(Tree T, int N)
{
    int v;
    int flag = 0;
    cin >> v;
    if (v != T->v)
        flag = 1;
    else
        T->flag = 1;

    for (int i = 1; i < N; i ++)
    {
        cin >> v;
        if ((!check(T, v)) && (!flag))
            flag = 1;
    }
    if (flag)
        return 0;
    else
        return 1;
}

void resetT(Tree T)
{
    if (T->left)
        resetT(T->left);
    if (T->right)
        resetT(T->right);
    T->flag = 0;
}

void freeTree(Tree T)
{
    if (T->left)
        freeTree(T->left);
    if (T->right)
        freeTree(T->right);
    free(T);
}

int main()
{
    int N, L;
    Tree T;

    cin >> N;
    while (N)
    {
        cin >> L;
        T = makeTree(N);
        for (int i = 0; i < L; i ++)
        {
            if (judge(T, N))
                cout << "Yes" << endl;
            else
                cout << "No" << endl;
            resetT(T);
        }
        freeTree(T);
        cin >> N;
    }
    return 0;
}
