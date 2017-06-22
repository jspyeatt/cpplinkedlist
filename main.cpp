#include <iostream>
#include <stdio.h>

using namespace std;

struct Node {
   int data;
   Node* next;
   };
void printList(Node *head);
Node* createNode(int value);
Node* appendToList(Node* head, int newValue);
Node* prependToList(Node* head, int newValue);

/** Creates a new node
 *
 * value - the value to assign to the new node.
 * return the node
 */

Node* createNode(int value) {
    // create the node
   Node* out = new Node();
   // assign the value and set next to NULL
   out->data = value;
   out->next = NULL;
   printf("createNode %p %d\n", out, out->data);
   return out;
}
/**
 * prints a linked list.
 */
void printList(Node *head)
{
    printf("============\n");
    printf("head = %p\n", head);
    while (head != NULL) {
        printf("%p %d %p\n", head, head->data, head->next);
        head = head->next;
    }
    printf("\n");
}
/**
 * appends a new value to the end of a linked list.
 *
 * head - the head of the linked list. Can be NULL.
 * newValue - the new value to add to the linked list.
 *
 * returns the head of the list. Should only change if the input value head == NULL.
 */
Node* appendToList(Node* head, int newValue) {
    printf("appendToList(%p, %d)\n", head, newValue);
    // create the new node.
    Node* newNode = createNode(newValue);
    Node* out = head;
    // if the head of the list is null, just assign the new node to be the head.
    if (head == NULL) {
        head = newNode;
    // if the head isn't null
    } else {
        // loop through the linked list until you find the last element.
        while (out->next != NULL) {
            out = out->next;
        }
        // point the next value for the last element to our new node, making it
        // the last element.
        out->next = newNode;
    }
    return head;
}
/**
 * prepends a new value to the beginning of a linked list.
 *
 * head - the head of the linked list. Can be NULL.
 * newValue - the new value to add to the linked list.
 *
 * returns the head of the list.
 */
Node* prependToList(Node *head, int newValue) {
    // create the new node
   Node* newNode = createNode(newValue);
   // if the head is not null point the new node's next value to the head.
   if (head != NULL) {
       newNode->next = head;
   }
   // the new node always becomes the new head.
   return newNode;
}

int main()
{
    Node* head = NULL;
    head = appendToList(head, 3);
    head = appendToList(head, 7);
    head = appendToList(head, 9);
    head = appendToList(head, 5);
    printList(head);
    head = prependToList(head, 21);
    printList(head);
    head = prependToList(head, 17);
    printList(head);

    return 0;
}
