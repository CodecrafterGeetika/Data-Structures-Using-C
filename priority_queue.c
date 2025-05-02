#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#define MAX 5

struct item {
    int data;
    int priority;
};

struct item pqueue[MAX];
int front = -1, rear = -1;

void insert();
void delete();
void display();

void main() {
    int choice;
    clrscr();
    
    while(1) {
        printf("\nPriority Queue Operations:");
        printf("\n1. Insert");
        printf("\n2. Delete");
        printf("\n3. Display");
        printf("\n4. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                insert();
                break;
            case 2:
                delete();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("\nInvalid choice!");
        }
    }
}

void insert() {
    struct item newitem;
    int i;
    
    if(rear == MAX-1) {
        printf("\nPriority Queue is full!");
        return;
    }
    
    printf("\nEnter data: ");
    scanf("%d", &newitem.data);
    printf("Enter priority: ");
    scanf("%d", &newitem.priority);
    
    if(front == -1) {
        front = rear = 0;
        pqueue[rear] = newitem;
    }
    else {
        for(i = rear; i >= front; i--) {
            if(newitem.priority > pqueue[i].priority) {
                pqueue[i+1] = pqueue[i];
            }
            else {
                break;
            }
        }
        pqueue[i+1] = newitem;
        rear++;
    }
    printf("\nItem inserted successfully!");
}

void delete() {
    if(front == -1 || front > rear) {
        printf("\nPriority Queue is empty!");
        return;
    }
    
    printf("\nDeleted item: Data = %d, Priority = %d", 
           pqueue[front].data, pqueue[front].priority);
    
    if(front == rear) {
        front = rear = -1;
    }
    else {
        front++;
    }
}

void display() {
    int i;
    
    if(front == -1 || front > rear) {
        printf("\nPriority Queue is empty!");
        return;
    }
    
    printf("\nPriority Queue Contents:");
    printf("\nData\tPriority");
    printf("\n----------------");
    
    for(i = front; i <= rear; i++) {
        printf("\n%d\t%d", pqueue[i].data, pqueue[i].priority);
    }
}