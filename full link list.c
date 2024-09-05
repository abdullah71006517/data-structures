#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node* next;
};

// Function to create a new node
struct node* create_node(int data) {
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = NULL;
    return newnode;
}

// Function to insert a node at the end of the linked list
void insertat_end(struct node** head, int data) {
    struct node* newnode = create_node(data);
    if (*head == NULL) {
        *head = newnode;
        return;
    }
    struct node* team = *head;
    while (team->next != NULL) {
        team = team->next;
    }
    team->next = newnode;
}

// Function to insert a node at the beginning of the linked list
void insertat_begin(struct node** head, int data) {
    struct node* newnode = create_node(data);
    newnode->next = *head;
    *head = newnode;
}

// Function to traverse and print the linked list
void traverse_linkedlist(struct node* head) {
    struct node* temp = head;
    while (temp != NULL) {
        printf("%d  ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Function to delete the first node in the linked list
struct node* dlt_begin(struct node* head) {
    if (head == NULL) {
        return NULL;
    }
    struct node* temp = head;
    head = head->next;
    free(temp);
    return head;
}

// Function to delete the last node in the linked list
struct node* dlt_end(struct node* head) {
    if (head == NULL) {  // List is empty
        return NULL;
    }

    if (head->next == NULL) {  // List has only one node
        free(head);
        return NULL;
    }

    // Traverse to the second last node
    struct node* second_lastnode = head;
    while (second_lastnode->next->next != NULL) {
        second_lastnode = second_lastnode->next;
    }

    // Free the last node and set second last node's next to NULL
    free(second_lastnode->next);
    second_lastnode->next = NULL;

    return head;
}

int main() {
    struct node* head = NULL;

    // Insert some nodes
    insertat_end(&head, 20);
    insertat_begin(&head, 10);
    insertat_end(&head, 30);

    // Delete the first node
    head = dlt_begin(head);

    // Delete the last node (uncomment the line below to test deleting the last node)
    // head = dlt_end(head);

    // Traverse and print the list
    traverse_linkedlist(head);

    return 0;
}
