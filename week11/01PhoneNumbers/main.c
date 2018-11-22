#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define MAXTABLESIZE 1000000
#define MAXD 5
#define KEYLENGTH 11

typedef char ELementType[KEYLENGTH + 1];

typedef struct LNode *PtrToLNode;
struct LNode {
    ELementType Data;
    PtrToLNode Next;
    int Count;
};


typedef PtrToLNode Position;
typedef PtrToLNode List;
typedef struct TblNode *HashTable;
struct TblNode {
    int TableSize;
    List Heads;
};

int NextPrime(int N) {
    int i;
    int p = (N % 2) ? N+2 : N+1;
    while (p <= MAXTABLESIZE) {
        for (i = (int)sqrt(p); i > 2; i --) {
            if (!(p%i))
                break;
        }
        if (i == 2)
            break;
        else
            p += 2;
    }
    return p;
}


HashTable CreateTable(int TableSize) {
    HashTable H;
    H = (HashTable) malloc(sizeof(struct TblNode));
    H->TableSize = NextPrime(TableSize);
    H->Heads = (List) malloc(H->TableSize*sizeof(struct LNode));
    for (int i = 0; i < H->TableSize; i ++) {
        H->Heads[i].Data[0] = '\0';
        H->Heads[i].Next = NULL;
        H->Heads[i].Count = 0;
    }
    return H;
}

int Hash(int Key, int p) {
    return Key % p;
}

Position Find(HashTable H, ELementType Key) {
    Position P;
    int Pos;

    Pos = Hash(atoi(Key + KEYLENGTH - MAXD), H->TableSize);
    P = H->Heads[Pos].Next;

    while (P && strcmp(P->Data, Key)) {
        P = P->Next;
    }

    return P;
}

void Insert(HashTable H, ELementType Key) {
    Position P, NewCell;
    int Pos;

    P = Find(H, Key);
    if (!P) {
        NewCell = (Position) malloc(sizeof(struct LNode));
        strcpy(NewCell->Data, Key);
        NewCell->Count = 1;
        Pos = Hash(atoi(Key + KEYLENGTH - MAXD),H->TableSize);
        NewCell->Next = H->Heads[Pos].Next;
        H->Heads[Pos].Next = NewCell;
    }
    else {
        P->Count ++;
    }
}

void ScanAndOutput(HashTable H) {
    int MaxCnt = 0;
    int PCnt = 0;
    ELementType MinPhone;
    List Ptr;
    MinPhone[0] = '\0';

    for (int i = 0; i < H->TableSize; i ++) {
        Ptr = H->Heads[i].Next;
        while (Ptr) {
            if (Ptr->Count > MaxCnt) {
                MaxCnt = Ptr->Count;
                strcpy(MinPhone, Ptr->Data);
                PCnt = 1;
            }
            else if (Ptr->Count == MaxCnt) {
                PCnt ++;
                if (strcmp(MinPhone, Ptr->Data) > 0)
                    strcpy(MinPhone, Ptr->Data);
            }
            Ptr = Ptr->Next;
        }
    }
    printf("%s %d", MinPhone, MaxCnt);
    if (PCnt > 1)
        printf(" %d", PCnt);
    printf("\n");
}

int main() {
    int N;
    ELementType Key;
    HashTable H;

    scanf("%d", &N);
    H = CreateTable(N*2);

    for (int i = 0; i < N; i ++) {
        scanf("%s", Key);
        Insert(H, Key);
        scanf("%s", Key);
        Insert(H, Key);
    }
    ScanAndOutput(H);

    return 0;
}
