#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct Node {
    int val;
    struct Node* next;
    struct Node* prev;
};

typedef struct Node Node;  // allow to write "Node" instead of "struct Node"

// useless and meanless
// struct List {
//     struct Node* head;
// };


void pushBack(Node** begin, int inserting_value)
{
    if (*begin == NULL) // list is empty
    {
        Node* node = malloc(sizeof(Node));
        node->val = inserting_value;
        node->prev = NULL;
        node->next = NULL;

        *begin = node;
        return;
    }

    Node** currentNode = begin;
    while ((*currentNode)->next != NULL)
        currentNode = &((*currentNode)->next);

    Node* node = malloc(sizeof(Node));
    node->val = inserting_value;
    node->next = NULL;
    node->prev = (*currentNode);
    (*currentNode)->next = node;
}

void pushFront(Node** begin, int value)
{
    Node* node = malloc(sizeof(Node));
    node->val = value;
    node->next = *begin;

    *begin = node;
}

int popFront(Node** begin)
{
    if (*begin == NULL)
        return INT_MIN;  // something which is supposed to be error signal

    Node* temp = (*begin)->next; // saved element which is next after Head
    int ret_value = (*begin)->val;
    free(*begin);
    *begin = temp; // first element address is wiped here

    return ret_value;
}

void printList(Node* head)
{
    Node* iter = head;
    while (iter != NULL)
    {
        printf("%d ", iter->val);
        iter = iter->next;
    }
}

int findElement(Node* head, int val) // 1 if found, otherwise 0
{
    Node* iter = head;
    while (iter != NULL)
    {
        if (iter->val == val)
            return 1;
        iter = iter->next;
    }

    return 0;
}

// int getElementByIndex(Node* head, int index) => homework
// int deleteElementByIndex(Node** head, int index) => homework
// void insertElementByIndex(Node** head, int index, int val) => homework


// void change_ptr(int **ptr)
// {
//     // must change ptr value
//     ptr = NULL;
// }

int main()
{
    int* ptr = malloc(sizeof(int));
    free(ptr);
    ptr = NULL;

    Node* begin = NULL; // list is empty

    pushBack(&begin, 1);
    pushBack(&begin, 2);
    pushBack(&begin, 3);
    pushBack(&begin, 4);
    pushBack(&begin, 5);
    pushFront(&begin, 0);

    printf("%d\n", findElement(begin, 10));
    printf("%d\n", findElement(begin, 1));
    printf("%d\n", findElement(begin, 5));
    printf("%d\n", findElement(begin, -100));

    // printList(begin);

    // int x = 5;
    // int* ptr = &x;

    // printf("ptr: %p\n", ptr);
    // printf("x: %d\n", x);

    // change_ptr(&ptr);

    // printf("ptr: %p\n", ptr);
    // printf("x: %d\n", x);

    return 0;
}