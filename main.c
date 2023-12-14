#include <stdio.h>
#include <stdlib.h>

// Estrutura para representar um nó na lista encadeada
typedef struct Node
{
    int data;
    struct Node *right;
    struct Node *left;
    struct Node *foward;
    struct Node *behind;
} Node;

// Estrutura para representar o grafo
typedef struct Graph
{
    Node **vertices;
    int numVertices;
} Graph;

// Função para inicializar um grafo
Graph *createGraph()
{
    Graph *graph = (Graph *)malloc(sizeof(Graph));
    graph->numVertices = 0;
    graph->vertices = NULL;

    return graph;
}

// Função para adicionar um novo vértice ao grafo
void addVertex(Graph *graph)
{
    graph->numVertices++;
    graph->vertices = realloc(graph->vertices, graph->numVertices * sizeof(Node *));
    graph->vertices[graph->numVertices - 1] = NULL;
}

// Função para adicionar uma aresta ao grafo
void addEdgeRight(Graph *graph, int startVertex, int endVertex)
{
    // Adiciona a aresta do startVertex para o endVertex

    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = endVertex;
    newNode->right = graph->vertices[startVertex];
    graph->vertices[startVertex] = newNode;
}

// Função para adicionar uma aresta ao grafo
void addEdgeLeft(Graph *graph, int startVertex, int endVertex)
{
    // Adiciona a aresta do startVertex para o endVertex

    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = endVertex;
    newNode->left = graph->vertices[startVertex];
    graph->vertices[startVertex] = newNode;
}

// Função para adicionar uma aresta ao grafo
void addEdgeFoward(Graph *graph, int startVertex, int endVertex)
{
    // Adiciona a aresta do startVertex para o endVertex

    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = endVertex;
    newNode->foward = graph->vertices[startVertex];
    graph->vertices[startVertex] = newNode;
}

// Função para adicionar uma aresta ao grafo
void addEdgeBehind(Graph *graph, int startVertex, int endVertex)
{
    // Adiciona a aresta do startVertex para o endVertex

    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = endVertex;
    newNode->behind = graph->vertices[startVertex];
    graph->vertices[startVertex] = newNode;
}




void decimalToBinary(Graph* maze, int decimal, int ratVertex)
{
    int binary[4];
    int i = 0;

    while (decimal > 0)
    {
        binary[i] = decimal % 2;
        decimal = decimal / 2;
        i++;
    }

    if(binary[0] == 1){
        addVertex(maze);
        addEdgeFoward(maze, ratVertex, maze->numVertices);
    }

    if(binary[1] == 1){
        addVertex(maze);
        addEdgeRight(maze, ratVertex, maze->numVertices);
    }

    if(binary[2] == 1){
        addVertex(maze);
        addEdgeBehind(maze, ratVertex, maze->numVertices);
    }

    if(binary[3] == 1){
        addVertex(maze);
        addEdgeLeft(maze, ratVertex, maze->numVertices);
    }
    
}

int main()
{
    int result;
    int ratVertex;
    char action;
    Graph *maze = createGraph();
    addVertex(maze);
    ratVertex = 0;

    addVertex(maze);
    addEdgeFoward(maze, ratVertex, maze->numVertices);

    addVertex(maze);
    addEdgeRight(maze, ratVertex, maze->numVertices);
    
    addVertex(maze);
    addEdgeLeft(maze, ratVertex, maze->numVertices);
    
    addVertex(maze);
    addEdgeBehind(maze, ratVertex, maze->numVertices);
    
    printGraph(maze);











    return 0;
}