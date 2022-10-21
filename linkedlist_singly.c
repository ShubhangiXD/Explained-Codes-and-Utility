#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};
// node has two sections - data and a next pointer

void insert_before(struct node **head_ptr, int key)
{
    // node is allocated a memory space
    struct node *new = (struct node *)malloc(sizeof(struct node));
    // the key is taken as the node's information
    new->data = key;
    // next of new node becomes the next pointer/head
    new->next = (*head_ptr);
    // making pointer/head point to the next new node
    (*head_ptr) = new;
}

void insert_after(struct node *prev, int key)
{
    //checking if prev is null
    if (prev == NULL)
    {
        printf("the given previous node cannot be NULL");
        return;
    }
    //allocating new node
    struct node *new = (struct node *)malloc(sizeof(struct node));
    //data for new node stored in key
    new->data = key;
    //new of next becomes 
    new->next = prev->next;
    //prev of next shifted to new
    prev->next = new;
}

void insert_end(struct node **head_ptr, int key)
{
    struct node *new = (struct node *)malloc(sizeof(struct node));
    struct node *last = (*head_ptr); // taking the last pointer to the present one
    // the key is stored as data
    new->data = key;
    // since the new node is the last node, the next of the new node will be NULL
    new->next = NULL;

    // if the linked list is empty, the new node becomes the new head pointer.
    if ((*head_ptr) == NULL)
    {
        (*head_ptr) = new;
        return;
    }

    // otherwise, the list is traversed till we reach the last node
    // last contains the head value; so if the last of next is not NULL, the next value is present;
    // so we change the last value to point to the next node
    while (last->next != NULL)
        last = last->next;

    // the last of next then becomes the new node.
    last->next = new;
    return;
}

void display(struct node *node)
{
    while (node != NULL)
    {
        printf(" %d ", node->data);
        node = node->next;
    }
}

int main()
{
    // this function is just to check whether the utility functions are working without the user inputs
    struct node *head = NULL;
    insert_end(&head, 6);       // list is 6->NULL
    insert_end(&head, 7);       // list is 6->7->NULL
    insert_before(&head, 1);    // list is 1->6->7->NULL
    insert_after(head->next, 8); // list is 1->6->8->7->NULL

    printf("The created list is: \n");
    display(head);
    return 0;
}
