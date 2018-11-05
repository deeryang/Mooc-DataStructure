#include <iostream>

using namespace std;

struct List {
    int val;
    List *next;
};

// 获取链表的长度
int getLength(List *list)
{
    List *ptr = list;
    if (ptr == NULL)
    {
        return 0;
    }
    else
    {
        int length = 0;
        while (ptr != NULL)
        {
            length ++;
            ptr = ptr->next;
        }
        return length;
    }
}

// 查找第k个元素
List* findKth(List *list, int k)
{
    List *ptr = list;
    if (ptr == NULL)
    {
        return NULL;
    }
    else
    {
        int index = 1;
        while (ptr != NULL & index < k)
        {
            index ++;
            ptr = ptr->next;
        }
        if (index == k)
        {
            return ptr;
        }
        else {
            return NULL;
        }
    }
}

// 查找值在链表中的位置
List* findKey(List *list, int value)
{
    List *ptr = list;
    if (ptr == NULL)
    {
        return NULL;
    }
    else
    {
        while (ptr != NULL)
        {
            if (ptr->val == value)
                return ptr;
            ptr = ptr->next;
        }
        return NULL;
    }
}

// 插入，在第i-1个节点后插入值为x的新节点
List* insertNode(List *list, int i, int x)
{

}

// 删除第i个位置的节点
List* deleteNode(List *list, int i)
{

}
