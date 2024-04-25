#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct {
    int data;
    int prev_index;
    int next_index;
} Node;

typedef struct {
    Node nodes[MAX_SIZE];
    int head;
    int tail;
    int free_index;
} DoublyLinkedList;

void init(DoublyLinkedList *list) {
    list->head = -1;
    list->tail = -1;
    list->free_index = 0;
    for (int i = 0; i < MAX_SIZE - 1; i++) {
        list->nodes[i].next_index = i + 1;
    }
    list->nodes[MAX_SIZE - 1].next_index = -1;
}

int alloc(DoublyLinkedList *list) {
    int index = list->free_index;
    list->free_index = list->nodes[index].next_index;
    return index;
}

void free_node(DoublyLinkedList *list, int index) {
    list->nodes[index].next_index = list->free_index;
    list->free_index = index;
}

void append(DoublyLinkedList *list, int data) {
    if (list->tail == MAX_SIZE - 1) {
        printf("List is full\n");
        return;
    }

    int new_index = alloc(list);
    list->nodes[new_index].data = data;
    list->nodes[new_index].prev_index = list->tail;
    list->nodes[new_index].next_index = -1;

    if (list->head == -1)
        list->head = new_index;
    else
        list->nodes[list->tail].next_index = new_index;

    list->tail = new_index;
}

void print_forward(DoublyLinkedList *list) {
    for (int current = list->head; current != -1; current = list->nodes[current].next_index)
        printf("%d ", list->nodes[current].data);
    printf("\n");
}

void print_backward(DoublyLinkedList *list) {
    for (int current = list->tail; current != -1; current = list->nodes[current].prev_index)
        printf("%d ", list->nodes[current].data);
    printf("\n");
}

int main() {
    DoublyLinkedList list;
    init(&list);

    append(&list, 4);
    append(&list, 2);
    append(&list, 3);

    printf("Forward: ");
    print_forward(&list);

    printf("Backward: ");
    print_backward(&list);

    return 0;
}#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct {
    int data;
    int prev_index;
    int next_index;
} Node;

typedef struct {
    Node nodes[MAX_SIZE];
    int head;
    int tail;
    int free_index;
} DoublyLinkedList;

void init(DoublyLinkedList *list) {
    list->head = -1;
    list->tail = -1;
    list->free_index = 0;
    for (int i = 0; i < MAX_SIZE - 1; i++) {
        list->nodes[i].next_index = i + 1;
    }
    list->nodes[MAX_SIZE - 1].next_index = -1;
}

int alloc(DoublyLinkedList *list) {
    int index = list->free_index;
    list->free_index = list->nodes[index].next_index;
    return index;
}

void free_node(DoublyLinkedList *list, int index) {
    list->nodes[index].next_index = list->free_index;
    list->free_index = index;
}

void append(DoublyLinkedList *list, int data) {
    if (list->tail == MAX_SIZE - 1) {
        printf("List is full\n");
        return;
    }

    int new_index = alloc(list);
    list->nodes[new_index].data = data;
    list->nodes[new_index].prev_index = list->tail;
    list->nodes[new_index].next_index = -1;

    if (list->head == -1)
        list->head = new_index;
    else
        list->nodes[list->tail].next_index = new_index;

    list->tail = new_index;
}

void print_forward(DoublyLinkedList *list) {
    for (int current = list->head; current != -1; current = list->nodes[current].next_index)
        printf("%d ", list->nodes[current].data);
    printf("\n");
}

void print_backward(DoublyLinkedList *list) {
    for (int current = list->tail; current != -1; current = list->nodes[current].prev_index)
        printf("%d ", list->nodes[current].data);
    printf("\n");
}

int main() {
    DoublyLinkedList list;
    init(&list);

    append(&list, 4);
    append(&list, 2);
    append(&list, 3);

    printf("Forward: ");
    print_forward(&list);

    printf("Backward: ");
    print_backward(&list);

    return 0;
}
