#include <stdio.h>
#include <stdlib.h>

// 原文：https://blog.csdn.net/feng_zhiyu/article/details/80612822

typedef int ElementType;
typedef struct Node *PtrToNode;
struct Node {
    ElementType Data;
    PtrToNode   Next;
};
typedef PtrToNode List;

List Read(); /* 细节在此不表 */
void Print( List L ); /* 细节在此不表；空链表将输出NULL */

List Merge( List L1, List L2 );

int main() {
    List L1, L2, L;
    L1 = Read();
    L2 = Read();
    L = Merge(L1, L2);
    Print(L);
    Print(L1);
    Print(L2);
    return 0;
}

List Read() {
    List r,L=(struct Node*)malloc(sizeof(struct Node));
    L->Next=NULL;
    r=L;
    int n;
    scanf("%d",&n);
    while(n--) {///尾插法
        Node *p=(struct Node*)malloc(sizeof(struct Node));
        scanf("%d",&p->Data);
        p->Next=NULL;
        r->Next=p;
        r=p;
    }
    return L;
}
List Merge(List L1,List L2) {
    List pa,pb,pc,L;
    L=(struct Node*)malloc(sizeof(struct Node));
    pc=L;
    pa=L1->Next,pb=L2->Next;
    while(pa&&pb) {
        if(pa->Data <= pb->Data) { ///取pa所指节点
            pc->Next=pa;           ///将pa所指节点链接到pc所指结点之后
            pc=pa;                  ///pc指向pa
            pa=pa->Next;            ///pa指向下一节点
        } else {                    ///取pb所指节点
            pc->Next=pb;
            pc=pb;
            pb=pb->Next;
        }
    }
    pc->Next=pa?pa:pb;          ///将非空链表的剩余段插入到pc所指节点后
    L1->Next=NULL; ///这里是根据题目要求输出合并后原链表的头结点所添加的。
    L2->Next=NULL; //
    return L;
}
void Print(List L) {
    if(L->Next) {
        List r=L;
        while(r->Next) {
            r=r->Next;
            printf("%d ",r->Data);
        }
        puts("");
    } else {
        printf("NULL\n");
    }
}


