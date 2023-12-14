#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct Graph {
    Node** vertices;
    int numVertices;
} Graph;

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
    newNode->next = graph->vertices[startVertex];
    graph->vertices[startVertex] = newNode;
}

void printGraph(Graph* graph) {
    for (int i = 0; i < graph->numVertices; i++) {
        Node* current = graph->vertices[i];
        printf("Vertex %d: ", i);

        while (current != NULL) {
            printf("%d -> ", current->data);
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
    }

    // Right
    if (binary[1] == 1) {
        addVertex(maze);
        addEdge(maze, ratVertex, maze->numVertices - 1);
        addEdge(maze, maze->numVertices - 1, ratVertex);
    }

    // Left
    if (binary[2] == 1) {
        addVertex(maze);
        addEdge(maze, ratVertex, maze->numVertices - 1);
        addEdge(maze, maze->numVertices - 1, ratVertex);
    }

    // Behind
    if (binary[3] == 1) {
        addVertex(maze);
        addEdge(maze, ratVertex, maze->numVertices - 1);
        addEdge(maze, maze->numVertices - 1, ratVertex);
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
