#include <iostream>
#include <stdlib.h>

using namespace std;

struct PolyNode {
    int coef;
    int expon;
    PolyNode* link;
};

void attach(int c, int e, PolyNode** pRear)
{
    PolyNode* P;
    P = (PolyNode*) malloc(sizeof(struct PolyNode));
    P->coef = c;
    P->expon = e;
    P->link = NULL;
    (*pRear)->link = P;
    *pRear = P;
}

PolyNode* readPoly()
{
    PolyNode *P;
    PolyNode *Rear;
    PolyNode *t;
    int c, e, N;

    cin >> N;
    P = (PolyNode*)malloc(sizeof(struct PolyNode));
    P->link = NULL;
    Rear = P;

    while (N--)
    {
        cin >> c >> e;
        attach(c, e, &Rear);
    }
    t = P;
    P = P->link;
    free(t);

    return P;
}

void printPoly(PolyNode* P)
{
    int flag = 0;

    if (!P)
    {
        cout << "0 0" << endl;
        return;
    }
    while (P)
    {
        if (!flag)
            flag = 1;
        else
            cout << " ";
        cout << P->coef << " " << P->expon;
        P = P->link;
    }
    cout << endl;
    return;
}

PolyNode* mult(PolyNode* P1, PolyNode* P2)
{
    PolyNode *P, *Rear, *t, *t1, *t2;
    int e, c;

    if (!P1 || !P2)
        return NULL;

    t1 = P1;
    t2 = P2;

    P = (PolyNode*) malloc(sizeof(struct PolyNode));
    P->link = NULL;
    Rear = P;

    while (t2)
    {
        attach(t1->coef * t2->coef, t1->expon + t2->expon, &Rear);
        t2 = t2->link;
    }
    t1 = t1->link;
    while (t1)
    {
        t2 = P2;
        Rear = P;
        while (t2)
        {
            e = t1->expon + t2->expon;
            c = t1->coef * t2->coef;
            while (Rear->link && Rear->link->expon > e)
                Rear = Rear->link;
            if (Rear->link && Rear->link->expon == e)
            {
                if (Rear->link->coef + c)
                    Rear->link->coef += c;
                else
                {
                    t = Rear->link;
                    Rear->link = t->link;
                    free(t);
                }
            }
            else
            {
                t = (PolyNode*) malloc(sizeof(struct PolyNode));
                t->coef = c;
                t->expon = e;
                t->link = Rear->link;
                Rear->link = t;
                Rear = Rear->link;
            }
            t2 = t2->link;
        }
        t1 = t1->link;
    }
    t2 = P;
    P = P->link;
    free(t2);

    return P;

}

int compare(int expon1, int expon2)
{
    if (expon1 > expon2)
        return 1;
    else if (expon1 < expon2)
        return -1;
    else
        return 0;
}

PolyNode* add(PolyNode* P1, PolyNode* P2)
{
    PolyNode *front;
    PolyNode *rear;
    PolyNode *temp;
    int sum;
    rear = (PolyNode*) malloc(sizeof(struct PolyNode));
    front = rear;

    while (P1 && P2)
    {
        switch (compare(P1->expon, P2->expon))
        {
        case 1:
            attach(P1->coef, P1->expon, &rear);
            P1 = P1->link;
            break;
        case -1:
            attach(P2->coef, P2->expon, &rear);
            P2 = P2->link;
            break;
        case 0:
            sum = P1->coef + P2->coef;
            if (sum)
                attach(sum, P1->expon, &rear);
            P1 = P1->link;
            P2 = P2->link;
            break;
        }
    }

    for ( ; P1; P1 = P1->link)
        attach(P1->coef, P1->expon, &rear);
    for ( ; P2; P2 = P2->link)
        attach(P2->coef, P2->expon, &rear);
    rear->link = NULL;
    temp = front;
    front = front->link;
    free(temp);

    return front;
}

int main()
{
    PolyNode *P1, *P2, *PP, *PS;
    P1 = readPoly();
    P2 = readPoly();
    PP = mult(P1, P2);
    printPoly(PP);
    PS = add(P1, P2);
    printPoly(PS);

    return 0;
}




