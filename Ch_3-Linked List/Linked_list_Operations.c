#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL;

void createNode(int val)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = val;
    newNode->next = NULL;

    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        struct node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void insertAtFront(int val)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = val;
    newNode->next = NULL;

    if (head == NULL)
    {
        head = newNode;
        return;
    }

    newNode->next = head;
    head = newNode;

    // alternate way
    // struct node *temp = head;
    // head = newNode;
    // head->next = temp;
}

void insertAtEnd(int val)
{
    createNode(val);
}

void insertAtKthPos(int val, int pos)
{

    if (pos == 1)
    {
        insertAtFront(val);
        return;
    }

    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = val;
    newNode->next = NULL;

    pos--;
    struct node *ptr = head;

    while (pos != 1)
    {
        ptr = ptr->next;
        pos--;
    }
    newNode->next = ptr->next;
    ptr->next = newNode;
}

void deleteFirst()
{
    if (head == NULL)
    {
        printf("\nList is already empty!");
        return;
    }
    struct node *temp = head;
    head = head->next;
    free(temp);
    temp = NULL;
}

void deleteLast()
{
    if (head == NULL)
    {
        printf("List is already empty!");
    }
    else if (head->next == NULL)
    {
        free(head);
        head = NULL;
    }
    else
    {
        struct node *temp = head;
        struct node *temp2 = head;

        while (temp->next != NULL)
        {
            temp2 = temp;
            temp = temp->next;
        }
        temp2->next = NULL;
        free(temp);
        temp = NULL;
    }
}

void del_pos(struct node **head, int pos)
{
    struct node *current = *head;
    struct node *previous = *head;

    if (*head == NULL)
    {
        printf("List is already empty!");
    }
    else if (pos == 1)
    {
        *head = current->next;
        free(current);
        current = NULL;
    }
    else
    {

        while (pos != 1)
        {
            previous = current;
            current = current->next;
            pos--;
        }
        previous->next = current->next;
        free(current);
        current = NULL;
    }
}

void searchElement(int val)
{
    if (head == NULL)
    {
        printf("\nList is empty!");
        return;
    }

    int pos = 1;
    struct node *temp = head;
    while (temp->next != NULL)
    {
        if (temp->data == val)
        {
            printf("\nElement found at %d position\n", pos);
            return;
        }
        pos++;
        temp = temp->next;
    }

    if (temp->data == val)
    {
        printf("\nElement found at %d position\n", pos);
    }
    else
    {
        printf("\nElement not found!\n");
    }
}

void displayList(struct node *head)
{
    if (head == NULL)
    {
        printf("\nList is empty!");
        return;
    }
    printf("\nThe list: ");
    struct node *temp = head;
    while (temp != NULL)
    {
        printf(" %d ->", temp->data);
        temp = temp->next;
    }
    printf(" NULL\n");
}

int main()
{
    int choice, size, value, k;

    while (1)
    {
        printf("\n_____________MENU_____________\n");
        printf("\n1. Create linked list");
        printf("\n2. Display the list");
        printf("\n3. Insert at front");
        printf("\n4. Insert at end");
        printf("\n5. Insert at any position");
        printf("\n6. Delete first node");
        printf("\n7. Delete last node");
        printf("\n8. Delete at any position");
        printf("\n9. Search a given element");
        printf("\n10. Exit");
        printf("\nEnter your choice -> ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("\nEnter the number of nodes in list: ");
            scanf("%d", &size);
            for (int i = 0; i < size; i++)
            {
                printf("Enter value of %d node: ", i + 1);
                scanf("%d", &value);
                createNode(value);
            }
            printf("\nLinked list created successfully!\n");
            break;

        case 2:
            displayList(head);
            break;

        case 3:
            printf("\nEnter value: ");
            scanf("%d", &value);
            insertAtFront(value);
            printf("\nValue added at front successfully!\n");
            break;

        case 4:
            printf("\nEnter value: ");
            scanf("%d", &value);
            insertAtEnd(value);
            printf("\nValue added at end successfully!\n");
            break;

        case 5:
            printf("\nEnter value: ");
            scanf("%d", &value);
            printf("\nEnter position: ");
            scanf("%d", &k);
            insertAtKthPos(value, k);
            printf("\nNode added at %dth position successfully!\n", k);
            break;

        case 6:
            deleteFirst();
            printf("\nFirst node is successfully deleted!");
            break;

        case 7:
            deleteLast();
            printf("\nLast node is successfully deleted!");
            break;

        case 8:
            printf("\nEnter position: ");
            scanf("%d", &k);
            del_pos(&head, k);
            printf("\nNode deleted at %dth position successfully!\n", k);
            break;

        case 9:
            printf("\nEnter element to be searched: ");
            scanf("%d", &value);
            searchElement(value);
            break;

        case 10:
            printf("\nExiting...");
            exit(0);

        default:
            printf("\nInvalid Choice!!!");
        }
    }
    return 0;
}