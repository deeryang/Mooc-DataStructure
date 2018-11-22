#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct TNode* Position;
typedef Position BinTree;
struct TNode {
    ElementType Data;
    BinTree     Left;
    BinTree     Right;
};

void PreorderTraversal(BinTree BST);
void InorderTraversal(BinTree BST);

BinTree Insert(BinTree BST, ElementType X);
BinTree Delete(BinTree BST, ElementType X);
Position Find(BinTree BST, ElementType X);
Position FindMin(BinTree BST);
Position FindMax(BinTree BST);

int main()
{
    BinTree BST, MinP, MaxP, Tmp;
    ElementType X;
    int N;

    BST = NULL;
    scanf("%d\n", &N);
    for (int i = 0; i < N; i ++) {
        scanf("%d", &X);
        BST = Insert(BST, X);
    }

    printf("Preorder: ");
    PreorderTraversal(BST);
    printf("\n");

    MinP = FindMin(BST);
    MaxP = FindMax(BST);

    scanf("%d\n", &N);
    for (int i = 0; i < N; i ++) {
        scanf("%d", &X);
        Tmp = Find(BST, X);
        if (Tmp == NULL)
            printf("%d is not found.\n", X);
        else {
            printf("%d is found\n", Tmp->Data);
            if (Tmp == MinP)
                printf("%d is the smallest key\n", Tmp->Data);
            if (Tmp == MaxP)
                printf("%d is the largest key\n", Tmp->Data);
        }
    }

    scanf("%d", &N);
    for (int i = 0; i < N; i ++) {
        scanf("%d", &X);
        BST = Delete(BST, X);
    }
    printf("Inorder: ");
    InorderTraversal(BST);
    printf("\n");

    return 0;
}

void PreorderTraversal(BinTree BST) {
    if (BST) {
        printf("%d ", BST->Data);
        PreorderTraversal(BST->Left);
        PreorderTraversal(BST->Right);
    }
}

void InorderTraversal(BinTree BST) {
    if (BST) {
        InorderTraversal(BST->Left);
        printf("%d ", BST->Data);
        InorderTraversal(BST->Right);
    }
}

BinTree Insert(BinTree BST, ElementType X) {
    if (BST == NULL) {
        BST = (BinTree) malloc(sizeof(struct TNode));
        BST->Data = X;
        BST->Left = NULL;
        BST->Right = NULL;
    }
    else {
        if (X < BST->Data)
            BST->Left = Insert(BST->Left, X);
        else if (X > BST->Data) {
            BST->Right = Insert(BST->Right, X);
        }
    }

    return BST;
}

BinTree Delete(BinTree BST, ElementType X) {
    Position Tmp;
    if (BST == NULL)
        printf("Not Found\n");
    else {
        if (X < BST->Data)
            BST->Left = Delete(BST->Left, X);
        else if (X > BST->Data)
            BST->Right = Delete(BST->Right, X);
        else {
            if (BST->Left && BST->Right) {
                Tmp = FindMin(BST->Right);
                BST->Data = Tmp->Data;
                BST->Right = Delete(BST->Right, BST->Data);
            }
            else {
                Tmp = BST;
                if (BST->Left == NULL)
                    BST = BST->Right;
                else
                    BST = BST->Left;
                free(Tmp);
        }
        }
    }

    return BST;
}

BinTree Find(BinTree BST, ElementType X) {
    if (BST == NULL)
        return NULL;
    if (X > BST->Data)
        return Find(BST->Right, X);
    else if (X < BST->Data)
        return Find(BST->Left, X);
    else
        return BST;
}

BinTree FindMin(BinTree BST) {
    if (BST == NULL)
        return NULL;
    else if (BST->Left == NULL)
        return BST;
    else
        return FindMin(BST->Left);
}

BinTree FindMax(BinTree BST) {
    if (BST == NULL)
        return NULL;
    else if (BST->Right == NULL)
        return BST;
    else
        return FindMax(BST->Right);
}
