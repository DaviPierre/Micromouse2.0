#include <stdio.h>
#include <stdlib.h>

// Estrutura para representar um nó na lista encadeada
typedef struct Node {
    int data;
    struct Node* right;
    struct Node* left;
    struct Node* foward;
    struct Node* behind;
} Node;

// Estrutura para representar o grafo
typedef struct Graph {
    Node** vertices;
    int numVertices;
} Graph;

// Função para inicializar um grafo
Graph* createGraph() {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->numVertices = 0;
    graph->vertices = NULL;

    return graph;
}

// Função para adicionar um novo vértice ao grafo
void addVertex(Graph* graph) {
    graph->numVertices++;
    graph->vertices = realloc(graph->vertices, graph->numVertices * sizeof(Node*));
    graph->vertices[graph->numVertices - 1] = NULL;
}

// Função para adicionar uma aresta ao grafo
void addEdgeRight(Graph* graph, int startVertex, int endVertex) {
    // Adiciona a aresta do startVertex para o endVertex

    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = endVertex;
    newNode->right = graph->vertices[startVertex];
    graph->vertices[startVertex] = newNode;
}

// Função para adicionar uma aresta ao grafo
void addEdgeLeft(Graph* graph, int startVertex, int endVertex) {
    // Adiciona a aresta do startVertex para o endVertex

    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = endVertex;
    newNode->left = graph->vertices[startVertex];
    graph->vertices[startVertex] = newNode;
}

// Função para adicionar uma aresta ao grafo
void addEdgeFoward(Graph* graph, int startVertex, int endVertex) {
    // Adiciona a aresta do startVertex para o endVertex

    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = endVertex;
    newNode->foward = graph->vertices[startVertex];
    graph->vertices[startVertex] = newNode;
}

// Função para adicionar uma aresta ao grafo
void addEdgeBehind(Graph* graph, int startVertex, int endVertex) {
    // Adiciona a aresta do startVertex para o endVertex

    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = endVertex;
    newNode->behind = graph->vertices[startVertex];
    graph->vertices[startVertex] = newNode;
}


int main()
{
    int result;
    char action;
    Graph* maze = createGraph();













    return 0;
}