#include <stdio.h>
#include <stdlib.h>

// Correct typedef syntax
typedef struct ListNode {
    int val;
    struct ListNode *next;
} ListNode;

// Reverse linked list function
struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode *prev = NULL;
    struct ListNode *current = head;
    struct ListNode *next = NULL;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}

// Function to test if list is a palindrome
void palindromeTest(struct ListNode* head) {
    struct ListNode *slow = head;
    struct ListNode *fast = head;

    // Find middle
    while (fast->next && fast->next->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // Reverse second half
    struct ListNode *reversedList = reverseList(slow->next);
    struct ListNode *firstHalf = head;

    // Compare
    while (reversedList != NULL) {
        if (firstHalf->val != reversedList->val) {
            printf("Not a palindrome\n");
            return;
        }
        firstHalf = firstHalf->next;
        reversedList = reversedList->next;
    }

    printf("Is a palindrome\n");
    return;
}

int main() {
    struct ListNode *head = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode *second = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode *third = (struct ListNode*)malloc(sizeof(struct ListNode));

    head->val = 1; head->next = second;
    second->val = 2; second->next = third;
    third->val = 1; third->next = NULL;

    palindromeTest(head);

    free(head);
    free(second);
    free(third);

    return 0;
}
