#include <iostream>

//#define Address char;
//#define Data    int;
//#define Next    char;

//using namespace std;

//struct LinkedList {

//};

//int main()
//{
//    return 0;
//}

typedef struct Node *PtrToNode;
struct Node {
    ElementType Data; /* 存储结点数据 */
    PtrToNode   Next; /* 指向下一个结点的指针 */
};
typedef PtrToNode List; /* 定义单链表类型 */

List Merge(List L1, List L2)
{
    List p1 = L1->Next;
    List p2 = L2->Next;

    if (p1 == NULL)
    {
        L2->Next = NULL;
        return p2;
    }
    else if (p2 == NULL)
    {
        L1->Next = NULL;
        return p1;
    }

    List pHead = NULL;
    return pHead;
}
