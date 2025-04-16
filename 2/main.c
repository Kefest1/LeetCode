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

int main(void) {
    struct ListNode *list = calloc(1, sizeof(struct ListNode));
    list->val = 2;
    list->next = calloc(1, sizeof(struct ListNode));
    list->next->val = 4;
    list->next->next = calloc(1, sizeof(struct ListNode));
    list->next->next->val = 3;


    int res = calculateReversedSum(list);
    struct ListNode *resList = generateReversedList(res);
    free(list->next->next);
    free(list->next);
    free(list);
    free(resList->next->next);
    free(resList->next);
    free(resList);
    return res;
}