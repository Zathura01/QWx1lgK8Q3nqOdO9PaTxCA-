#include<stdio.h>
#include<stdlib.h>

typedef struct ListNode
{
    int val;
    struct ListNode* next;
} ListNode;


void runReverse(ListNode* listHead){

    ListNode* node = listHead;
    ListNode* next = NULL;
    ListNode* prev = NULL;

    while(node!=NULL){
        next = node->next;
        node->next = prev;
        prev = node;
        if(next == NULL){
            break;
        }
        node = next;
    }

    while(node!=NULL){

        printf("%d", node->val);
        node = node->next;
    }

}

int main(){

    ListNode* nodea = (ListNode*)malloc(sizeof(ListNode));
    ListNode* nodeb = (ListNode*)malloc(sizeof(ListNode));
    ListNode* nodec = (ListNode*)malloc(sizeof(ListNode));
    ListNode* noded = (ListNode*)malloc(sizeof(ListNode));

    nodea->val = 4;
    nodeb->val = 1;
    nodec->val = 5;
    noded->val = 3;

    nodea->next = nodeb;
    nodeb->next = nodec;
    nodec->next = noded;
    noded->next = NULL;

    runReverse(nodea);


    return 0;
}
