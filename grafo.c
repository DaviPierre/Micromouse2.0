#include <stdio.h>
#include <stdlib.h>

// Estrutura para representar um nó na lista encadeada
typedef struct Node {
    int data;
    struct Node* next;
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
void addEdge(Graph* graph, int startVertex, int endVertex) {
    // Adiciona a aresta do startVertex para o endVertex

    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = endVertex;
    newNode->next = graph->vertices[startVertex];
    graph->vertices[startVertex] = newNode;
}

// Função para imprimir o grafo
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

// Função principal
int main() {
    Graph* myGraph = createGraph();

    addVertex(myGraph);
    addVertex(myGraph);
    addVertex(myGraph);
    addVertex(myGraph);

    addEdge(myGraph, 0, 1);
    addEdge(myGraph, 0, 3);
    addEdge(myGraph, 1, 2);
    addEdge(myGraph, 2, 3);

    printGraph(myGraph);

    return 0;
}
