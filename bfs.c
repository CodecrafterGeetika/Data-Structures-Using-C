#include <stdio.h>
#include <conio.h>
#define MAX 20

int adj[MAX][MAX];
int visited[MAX];
int queue[MAX], front = -1, rear = -1;

void create_graph();
void display();
void bfs(int start);
void insert_queue(int vertex);
int delete_queue();
int isEmpty_queue();

void main() {
    int i, start;
    clrscr();
    
    create_graph();
    display();
    
    printf("\nEnter starting vertex for BFS: ");
    scanf("%d", &start);
    
    for(i = 0; i < MAX; i++)
        visited[i] = 0;
    
    printf("\nBFS traversal: ");
    bfs(start);
    
    getch();
}

void create_graph() {
    int i, max_edges, origin, destin;
    
    printf("Enter number of vertices (max %d): ", MAX);
    scanf("%d", &max_edges);
    
    for(i = 1; i <= max_edges; i++) {
        printf("Enter edge %d (-1 -1 to quit): ", i);
        scanf("%d %d", &origin, &destin);
        
        if((origin == -1) && (destin == -1))
            break;
            
        if(origin >= max_edges || destin >= max_edges || origin < 0 || destin < 0) {
            printf("Invalid edge!\n");
            i--;
        }
        else {
            adj[origin][destin] = 1;
            adj[destin][origin] = 1; // For undirected graph
        }
    }
}

void display() {
    int i, j;
    
    printf("\nAdjacency Matrix:\n");
    for(i = 0; i < MAX; i++) {
        for(j = 0; j < MAX; j++)
            printf("%4d", adj[i][j]);
        printf("\n");
    }
}

void bfs(int start) {
    int i, vertex;
    
    insert_queue(start);
    visited[start] = 1;
    
    while(!isEmpty_queue()) {
        vertex = delete_queue();
        printf("%4d", vertex);
        
        for(i = 0; i < MAX; i++) {
            if(adj[vertex][i] == 1 && visited[i] == 0) {
                insert_queue(i);
                visited[i] = 1;
            }
        }
    }
}

void insert_queue(int vertex) {
    if(rear == MAX-1)
        printf("Queue Overflow\n");
    else {
        if(front == -1)
            front = 0;
        rear = rear + 1;
        queue[rear] = vertex;
    }
}

int delete_queue() {
    int item;
    if(front == -1 || front > rear) {
        printf("Queue Underflow\n");
        return -1;
    }
    else {
        item = queue[front];
        front = front + 1;
        return item;
    }
}

int isEmpty_queue() {
    if(front == -1 || front > rear)
        return 1;
    else
        return 0;
}