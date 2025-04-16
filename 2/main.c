#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

void calculateReversedSumHelper(struct ListNode *list, int *sum) {
    if (list->next != NULL) {
        calculateReversedSumHelper(list->next, sum);
    }
    *sum *= 10;
    *sum += list->val;
}

int calculateReversedSum(struct ListNode *list) {
    int sum = 0;
    calculateReversedSumHelper(list, &sum);
    return sum;
}

void generateReversedListHelper(struct ListNode **curr, int number) {
    if (number != 0) {
        generateReversedListHelper(curr, number / 10);
    }
    struct ListNode *list = calloc(1, sizeof(struct ListNode));
    list->val = number % 10;
    (*curr)->next = list;
    *curr = (*curr)->next;
}

struct ListNode *generateReversedList(int number) {
    struct ListNode *list = calloc(1, sizeof(struct ListNode));
    struct ListNode *ptr = list;

    list->val = number % 10;
    number /= 10;

    for (int i = 0; number != 0; i++) {
        struct ListNode *next = calloc(1, sizeof(struct ListNode));
        next->val = number % 10;
        number /= 10;
        ptr->next = next;
        ptr = ptr->next;
    }

    return list;
}

void printList(struct ListNode *list) {
    while (list != NULL) {
        printf("%d ", list->val);
        list = list->next;
    }
    putchar(10);
}

int main(void) {
    struct ListNode *list1 = calloc(1, sizeof(struct ListNode));
    list1->val = 2;
    list1->next = calloc(1, sizeof(struct ListNode));
    list1->next->val = 4;
    list1->next->next = calloc(1, sizeof(struct ListNode));
    list1->next->next->val = 3;

    struct ListNode *list2 = calloc(1, sizeof(struct ListNode));
    list2->val = 5;
    list2->next = calloc(1, sizeof(struct ListNode));
    list2->next->val = 6;
    list2->next->next = calloc(1, sizeof(struct ListNode));
    list2->next->next->val = 4;

    int res1 = calculateReversedSum(list1);
    int res2 = calculateReversedSum(list2);
    int sum = res1 + res2;

    struct ListNode *resList = generateReversedList(sum);
    printList(resList);

    free(list1->next->next);
    free(list1->next);
    free(list1);
    free(list2->next->next);
    free(list2->next);
    free(list2);

    free(resList->next->next);
    free(resList->next);
    free(resList);

    return 0;
}