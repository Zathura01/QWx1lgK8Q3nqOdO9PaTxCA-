#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode
{
    int val;
    struct ListNode *next;
} ListNode;

ListNode **arrayOfListPointers(ListNode *a, ListNode *b)
{
    ListNode **listPointers = (ListNode **)malloc(2 * sizeof(ListNode *));
    listPointers[0] = a;
    listPointers[1] = b;
    return listPointers;
}

ListNode **intersection(ListNode *heada, ListNode *headb)
{
    ListNode *a = heada;
    ListNode *b = headb;

    while (a != b)
    {
        if (a == NULL)
        {
            a = headb;
        }
        else
        {
            a = a->next;
        }
        if (b == NULL)
        {
            b = heada;
        }
        else
        {
            b = b->next;
        }
    }
    return arrayOfListPointers(a, b);
}

int main()
{
    ListNode *headone = (ListNode *)malloc(sizeof(ListNode));
    ListNode *second = (ListNode *)malloc(sizeof(ListNode));
    ListNode *third = (ListNode *)malloc(sizeof(ListNode));
    headone->val = 1;
    headone->next = second;
    second->val = 2;
    second->next = third;
    third->val = 3;
    third->next = NULL;

    ListNode *headtwo = (ListNode *)malloc(sizeof(ListNode));
    ListNode *forth = (ListNode *)malloc(sizeof(ListNode));
    ListNode *fifth = (ListNode *)malloc(sizeof(ListNode));
    headtwo->val = 5;
    headtwo->next = forth;
    forth->val = 2;
    forth->next = fifth;
    fifth->val = 8;
     fifth->next = second;
    second->val = 2;
    second->next = third;
    third->val = 3;
    third->next = NULL;

    ListNode **array = intersection(headone, headtwo);
    ListNode *heada = array[0];
    ListNode *headb = array[1];
    while (heada != NULL)
    {
        printf("%d ", heada->val);
        heada = heada->next;
    }
    while (headb != NULL)
    {
        printf("%d ", headb->val);
        headb = headb->next;
    }
    return 0;
}
