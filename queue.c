
#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

/* Add an item to the rear of the dynamically-allocated queue.
 * Returns:  pointer to the item if successful, NULL if not. */
ItemType *enqueue(Queue *queue, ItemType *item) {

    //the newNode will be the currently active node
    ListNode *newNode = (ListNode*) malloc(sizeof (ListNode));

    //check if the new node is NULL
    if (newNode == NULL) {
        return NULL;
    }

    //connect the new ListNode to the item
    newNode->item = item;
    
    //set the next node as NULL
    newNode->next = NULL;

    //if the queue is empty, assign the newNode to the front, otherwise
    //assign it to the rear
    if (queue->front == NULL) {
        queue->front = newNode;
    } else {
        queue->rear->next = newNode;
    }

    //assign the newNode to the rear of the queue
    queue->rear = newNode;

    //increase the size of the queue
    queue->size++;

    //return the item pointer
    return item;
}

/* Removes an item from the front of the queue.
 * Returns:  pointer to the item if successful, NULL if empty */
ItemType *dequeue(Queue *queue) {
    //check if the queue is empty and return NULL
    if (queue->front == NULL) {
        return NULL;
    }
    
    //make a pointer to the front of the queue
    ListNode *ptr;
    ptr = queue->front;

    //move the front of the queue to the next item
    queue->front = queue->front->next;

    //decrease the size of the queue
    queue->size--;

    //if the queue is now empty, return NULL
    if (queue->size == 0) {
        queue->rear == NULL;
    }

    //create a pointer to the old item
    ItemType *intPtr;
    intPtr = ptr->item;

    //clear the node from cache
    free(ptr);

    //return the old item
    return intPtr;
}

/* Returns:  number of items in the queue */
int queueSize(const Queue queue) {
    return queue.size;
}

/* Print the contents of the queue to the specified stream */
void printQueue(const Queue queue, FILE *stream) {
    //local variable to store the current node
    ListNode *node = queue.front;
    
    //while the active node is not NULL, meaning not at the end yet and
    //print the contents of the queue to the screen
    while (node != NULL) {
        fprintf(stream, ITEM_FORMAT"\n", *(node->item));
        node = node->next;
    }
}
