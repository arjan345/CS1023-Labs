#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

struct node {
    int value;
    struct node *next;
};

void clear_InputBuffer(void);
struct node *create_Node(int value);
void append_Node(struct node **head, int value);
void print_List(const struct node *head);
size_t count_Nodes(const struct node *head);
int sum_Nodes(const struct node *head);
int search_List(const struct node *head, int target);
void free_List(struct node *head);

void clear_InputBuffer(void)
{
    int ch;

    while ((ch = getchar()) != '\n' && ch != EOF) {
        
    }
}

struct node *create_Node(int value)
{
    struct node *newNode = malloc(sizeof(struct node));

    if (newNode == NULL) {
        return NULL;
    }

    newNode->value = value;
    newNode->next = NULL;

    return newNode;
}

void append_Node(struct node **head, int value)
{
    struct node *newNode = create_Node(value);

    if (newNode == NULL) {
        printf("Error!!!!!memory allocation failed during adding %d.\n", value);
        free_List(*head);
        exit(1);
    }

    if (*head == NULL) {
        *head = newNode;
    } else {
        struct node *current = *head;

        while (current->next != NULL) {
            current = current->next;
        }

        current->next = newNode;
    }
}

void print_List(const struct node *head)
{
    const struct node *current = head;

    printf("List values: ");
    if (current == NULL) {
        printf("(empty)");
    }

    while (current != NULL) {
        printf("%d", current->value);
        if (current->next != NULL) {
            printf(" -> ");
        }
        current = current->next;
    }
    printf("\n");
}

size_t count_Nodes(const struct node *head)
{
    size_t count = 0;
    const struct node *current = head;

    while (current != NULL) {
        count++;
        current = current->next;
    }

    return count;
}

int sum_Nodes(const struct node *head)
{
    int sum = 0;
    const struct node *current = head;

    while (current != NULL) {
        sum += current->value;
        current = current->next;
    }

    return sum;
}

int search_List(const struct node *head, int target)
{
    const struct node *current = head;

    while (current != NULL) {
        if (current->value == target) {
            return 1;
        }
        current = current->next;
    }

    return 0;
}

void free_List(struct node *head)
{
    struct node *current = head;

    while (current != NULL) {
        struct node *nextNode = current->next;
        free(current);
        current = nextNode;
    }
}

int main(void)
{
    struct node *head = NULL;
    long countInput;
    int value;
    int target;

   
    printf("How many integers you want to add? ");

    if (scanf("%ld", &countInput) != 1) {
        printf("Error!!! the count must be an integer.\n");
        return 1;
    }

    if (countInput < 0) {
        printf("Error!!!  the count cannot be negative.\n");
        return 1;
    }

    for (long i = 0; i < countInput; i++) {
        int validInput = 0;

        while (!validInput) {
            printf("Enter integer %ld: ", i + 1);
            if (scanf("%d", &value) == 1) {
                append_Node(&head, value);
                validInput = 1;
            } else {
                printf("Invalid integer. Try again.\n");
                clear_InputBuffer();
            }
        }
    }

    printf("\nResults\n");
    print_List(head);
    printf("Number of nodes: %zu\n", count_Nodes(head));
    printf("Sum of values: %d\n", sum_Nodes(head));

    printf("\nEnter a value to search for: ");
    if (scanf("%d", &target) != 1) {
        printf("Error!!! search value must be an integer.\n");
        free_List(head);
        return 1;
    }

    if (search_List(head, target)) {
        printf("Value %d was found in the list.\n", target);
    } else {
        printf("Value %d was not found in the list.\n", target);
    }

    free_List(head);
    head = NULL;

    printf("Memory released....... Program is finished.\n");

    return 0;
}