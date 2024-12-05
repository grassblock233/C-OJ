/*链表的一系列操作*/

#include <stdio.h>
#include <stdlib.h>

/*定义链表结构体*/
struct ListNode
{
    int element;
    struct ListNode *next;
};

typedef struct ListNode *Node;

/*初始化链表*/
void initList(Node head)
{
    head->next = NULL;
}

/*链表的打印*/
void printList(Node head)
{
    printf("O");
    while (1)
    {
        if (head->next == NULL)
        {
            printf("\n");
            break;
        }
        head = head->next; // 头节点不存在
        printf("->%d", head->element);
    }
}

/*链表的插入*/
_Bool insertList(Node head, int element, int index)
{
    /*检查插入位置是否合法*/
    if (index < 1)
    {
        return 0;
    }
    /*note:注意这里要先index--一次*/
    for (index--; index > 0; index--)
    {
        if (head->next == NULL)
        {
            return 0;
        }
        head = head->next;
    }

    /*插入元素*/
    Node nodeinsert = malloc(sizeof(struct ListNode));
    if (nodeinsert == NULL)
    {
        return 0;
    }
    nodeinsert->next = head->next;
    nodeinsert->element = element;
    head->next = nodeinsert;
    return 1;
}

/*链表的删除*/
_Bool deleteList(Node head, int index)
{
    /*检查删除位置是否合法*/
    if (index < 1)
    {
        return 0;
    }
    for (index--; index > 0; index--)
    {
        if (head->next == NULL)
        {
            return 0;
        }
        head = head->next;
    }

    /*note:这里不能先free(head->next)，这样就没法找到后续结点了*/
    Node tmp = head->next;
    head->next = head->next->next;
    free(tmp);
    return 1;
}

/*获取对应位置上的元素*/
_Bool getList(Node head, int index)
{
    if (index < 1)
    {
        return 0;
    }
    for (; index > 0; index--)
    {
        if (head->next == NULL)
        {
            return 0;
        }
        head = head->next;
    }
    printf("elment:%d\n", head->element);
    return 1;
}

/*获取元素的对应位置*/
int findList(Node head, int element)
{
    int loc = 1;
    head = head->next;
    while (head->next != NULL)
    {
        if (head->element == element)
        {
            return loc;
        }
        head = head->next;
        loc++;
    }
    return -1;
}

/*获取链表长度*/
int lengthList(Node head)
{
    int length = 0;
    while (head->next != NULL)
    {
        head = head->next;
        length++;
    }
    return length;
}

int main()
{
    struct ListNode list;
    initList(&list);
    if (insertList(&list, 100, 1) == 0)
    {
        printf("Insert Failed");
    }
    if (insertList(&list, 200, 1) == 0)
    {
        printf("Insert Failed");
    }
    if (insertList(&list, 4579, 1) == 0)
    {
        printf("Insert Failed");
    }
    if (deleteList(&list, 3) == 0)
    {
        printf("Delete Failed");
    }
    if (getList(&list, 2) == 0)
    {
        printf("Delete Failed");
    }
    printList(&list);
    printf("%d\n", findList(&list, 100));
    printf("length List:%d\n", lengthList(&list));
    return 0;
}