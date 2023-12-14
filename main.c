#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
    int connectedRight;
    int connectedLeft;
    int connectedFoward;
    int connectedBehind;
} Node;

typedef struct Graph {
    Node** vertices;
    int numVertices;
} Graph; // deletar depois

Graph* createGraph() {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->numVertices = 0;
    graph->vertices = NULL;

    return graph;
}

void addVertex(Graph* graph) {
    graph->numVertices++;
    graph->vertices = realloc(graph->vertices, graph->numVertices * sizeof(Node*));
    graph->vertices[graph->numVertices - 1] = NULL;
}

void addEdge(Graph* graph, int startVertex, int endVertex) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = endVertex;
    newNode->connectedRight = 0;
    newNode->connectedLeft = 0;
    newNode->connectedFoward = 0;
    newNode->connectedBehind = 0;
    newNode->next = graph->vertices[startVertex];
    graph->vertices[startVertex] = newNode;
}

void printGraph(Graph* graph) {
    for (int i = 0; i < graph->numVertices; i++) {
        Node* current = graph->vertices[i];
        printf("Vertex %d (Connected to): ", i);

        while (current != NULL) {
            if (current->connectedRight)
                printf("Right ");
            if (current->connectedLeft)
                printf("Left ");
            if (current->connectedFoward)
                printf("Foward ");
            if (current->connectedBehind)
                printf("Behind ");

            printf("(%d) -> ", current->data);
            current = current->next;
        }

        printf("NULL\n");
    }
}

void decimalToBinary(Graph* maze, int decimal, int ratVertex) {
    int binary[4];
    int i = 0;

    while (decimal > 0) {
        binary[i] = decimal % 2;
        decimal = decimal / 2;
        i++;
    }

    // Foward
    if (binary[0] == 1) {
        addVertex(maze);
        addEdge(maze, ratVertex, maze->numVertices - 1);
        addEdge(maze, maze->numVertices - 1, ratVertex);
        maze->vertices[ratVertex]->connectedFoward = 1;
        maze->vertices[maze->numVertices - 1]->connectedBehind = 1;
    }

    // Right
    if (binary[1] == 1) {
        addVertex(maze);
        addEdge(maze, ratVertex, maze->numVertices - 1);
        addEdge(maze, maze->numVertices - 1, ratVertex);
        maze->vertices[ratVertex]->connectedRight = 1;
        maze->vertices[maze->numVertices - 1]->connectedLeft = 1;
    }

    // Left
    if (binary[2] == 1) {
        addVertex(maze);
        addEdge(maze, ratVertex, maze->numVertices - 1);
        addEdge(maze, maze->numVertices - 1, ratVertex);
        maze->vertices[ratVertex]->connectedLeft = 1;
        maze->vertices[maze->numVertices - 1]->connectedRight = 1;
    }

    // Behind
    if (binary[3] == 1) {
        addVertex(maze);
        addEdge(maze, ratVertex, maze->numVertices - 1);
        addEdge(maze, maze->numVertices - 1, ratVertex);
        maze->vertices[ratVertex]->connectedBehind = 1;
        maze->vertices[maze->numVertices - 1]->connectedFoward = 1;
    }
}

int main() {
    int ratVertex = 0;
    int result;
    Graph* maze = createGraph();
    addVertex(maze);

    printf("c");
    scanf("%d", &result);
    decimalToBinary(maze, result, ratVertex);

    printGraph(maze);

    return 0;
}
