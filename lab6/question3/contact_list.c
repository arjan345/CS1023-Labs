#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define name_LENGTH 50
#define number_LENGTH 20
#define input_LENGTH 100

struct contact {
    char name[name_LENGTH];
    char number[number_LENGTH];     
    struct contact *next;
};

void readLine(const char prompt[], char input[], size_t size);
int readMenuChoice(void);
struct contact *createContact(const char name[], const char number[]);
void addContact(struct contact **head, const char name[], const char number[]);
void displayContacts(const struct contact *head);
void findByName(struct contact *head, const char name[]);
void findByNumber(struct contact *head, const char number[]);
int updateNumber(struct contact *head, const char name[], const char newNumber[]);
int deleteByName(struct contact **head, const char name[]);
int deleteByNumber(struct contact **head, const char number[]);
size_t countContacts(const struct contact *head);
void freeContacts(struct contact *head);
void printMenu(void);

void readLine(const char prompt[], char input[], size_t size)
{
    size_t length;

    printf("%s", prompt);

    if (fgets(input, (int) size, stdin) == NULL) {
        input[0] = '\0';
        return;
    }

    length = strlen(input);
    if (length > 0 && input[length - 1] == '\n') {
        input[length - 1] = '\0';
    } else {
        int ch;
        while ((ch = getchar()) != '\n' && ch != EOF) {
          
        }
    }
}

int readMenuChoice(void)
{
    char input[input_LENGTH];
    char *endPtr;
    long choice;

    readLine("Enter your choice: ", input, sizeof(input));

    choice = strtol(input, &endPtr, 10);
    if (input[0] == '\0' || *endPtr != '\0' || choice < 1 || choice > 9) {
        return -1;
    }

    return (int) choice;
}

struct contact *createContact(const char name[], const char number[])
{
    struct contact *newContact = malloc(sizeof(struct contact));

    if (newContact == NULL) {
        return NULL;
    }

    strncpy(newContact->name, name, name_LENGTH - 1);
    newContact->name[name_LENGTH - 1] = '\0';

    strncpy(newContact->number, number, number_LENGTH - 1);
    newContact->number[number_LENGTH - 1] = '\0';

    newContact->next = NULL;

    return newContact;
}

void addContact(struct contact **head, const char name[], const char number[])
{
    struct contact *newContact = createContact(name, number);

    if (newContact == NULL) {
        printf("Error!!! memory allocation failed. Contact was not added.\n");
        return;
    }

    if (*head == NULL) {
        *head = newContact;
    } else {
        struct contact *current = *head;

        while (current->next != NULL) {
            current = current->next;
        }

        current->next = newContact;
    }

    printf("Contact added successfully.\n");
}

void displayContacts(const struct contact *head)
{
    const struct contact *current = head;
    size_t position = 1;

    if (current == NULL) {
        printf("The contact list is empty.\n");
        return;
    }

    printf("\nContact List\n");
    while (current != NULL) {
        printf("%zu. Name: %s | Phone: %s\n", position, current->name, current->number);
        current = current->next;
        position++;
    }
}

void findByName(struct contact *head, const char name[])
{
    struct contact *current = head;

    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            printf("Found contact: %s | Phone: %s\n", current->name, current->number);
            return;
        }
        current = current->next;
    }

    printf("No contact found with name: %s\n", name);
}

void findByNumber(struct contact *head, const char number[])
{
    struct contact *current = head;

    while (current != NULL) {
        if (strcmp(current->number, number) == 0) {
            printf("Found contact: %s | Phone: %s\n", current->name, current->number);
            return;
        }
        current = current->next;
    }

    printf("No contact found with phone number: %s\n", number);
}

int updateNumber(struct contact *head, const char name[], const char newNumber[])
{
    struct contact *current = head;

    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            strncpy(current->number, newNumber, number_LENGTH - 1);
            current->number[number_LENGTH - 1] = '\0';
            return 1;
        }
        current = current->next;
    }

    return 0;
}

int deleteByName(struct contact **head, const char name[])
{
    struct contact *current = *head;
    struct contact *previous = NULL;

    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            if (previous == NULL) {
                *head = current->next;
            } else {
                previous->next = current->next;
            }
            free(current);
            return 1;
        }
        previous = current;
        current = current->next;
    }

    return 0;
}

int deleteByNumber(struct contact **head, const char number[])
{
    struct contact *current = *head;
    struct contact *previous = NULL;

    while (current != NULL) {
        if (strcmp(current->number, number) == 0) {
            if (previous == NULL) {
                *head = current->next;
            } else {
                previous->next = current->next;
            }
            free(current);
            return 1;
        }
        previous = current;
        current = current->next;
    }

    return 0;
}

size_t countContacts(const struct contact *head)
{
    size_t count = 0;
    const struct contact *current = head;

    while (current != NULL) {
        count++;
        current = current->next;
    }

    return count;
}

void freeContacts(struct contact *head)
{
    struct contact *current = head;

    while (current != NULL) {
        struct contact *nextContact = current->next;
        free(current);
        current = nextContact;
    }
}

void printMenu(void)
{
    printf("\nContact List Menu\n");
    printf("1. <Add a new contact>\n");
    printf("2. <Display all contacts>\n");
    printf("3. <Search for a contact by name>\n");
    printf("4. <Search for a contact by phone number>\n");
    printf("5. <Update the phone number for an existing contact>\n");
    printf("6. <Delete a contact by name>\n");
    printf("7. <Delete a contact by phone number>\n");
    printf("8. <Count how many contacts are stored>\n");
    printf("9. Exit\n");
}

int main(void)
{
    struct contact *head = NULL;
    int running = 1;

    printf("Contact List Using a Linked List\n");

    while (running) {
        int choice;
        char name[name_LENGTH];
        char number[number_LENGTH];
        char newNumber[number_LENGTH];

        printMenu();
        choice = readMenuChoice();

        switch (choice) {
            case 1:
                readLine("Enter name> ", name, sizeof(name));
                readLine("Enter phone number> ", number, sizeof(number));
                addContact(&head, name, number);
                break;

            case 2:
                displayContacts(head);
                break;

            case 3:
                readLine("Enter name to search> ", name, sizeof(name));
                findByName(head, name);
                break;

            case 4:
                readLine("Enter phone number to search> ", number, sizeof(number));
                findByNumber(head, number);
                break;

            case 5:
                readLine("Enter contact name to update> ", name, sizeof(name));
                readLine("Enter new phone number> ", newNumber, sizeof(newNumber));
                if (updateNumber(head, name, newNumber)) {
                    printf("Phone number updated successfully.\n");
                } else {
                    printf("No contact found with name: %s\n", name);
                }
                break;

            case 6:
                readLine("Enter name to delete> ", name, sizeof(name));
                if (deleteByName(&head, name)) {
                    printf("Contact deleted by name.\n");
                } else {
                    printf("No contact found with name: %s\n", name);
                }
                break;

            case 7:
                readLine("Enter phone number to delete> ", number, sizeof(number));
                if (deleteByNumber(&head, number)) {
                    printf("Contact deleted by phone number.\n");
                } else {
                    printf("No contact found with phone number: %s\n", number);
                }
                break;

            case 8:
                printf("Number of contacts stored: %zu\n", countContacts(head));
                break;

            case 9:
                freeContacts(head);
                head = NULL;
                printf("All remaining contacts were freed! Program finished.\n");
                running = 0;
                break;

            default:
                printf("Invalid choice!!! Please enter a number from 1 to 9.\n");
                break;
        }
    }

    return 0;
}
