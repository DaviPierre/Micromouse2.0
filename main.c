#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
    struct Node *forward;
    struct Node *right;
    struct Node *left;
    struct Node *behind;
} Node;

typedef struct Graph
{
    Node **vertices;
    int numVertices;
    int ratVertex;

} Graph;

Graph *createGraph()
{
    Graph *graph = (Graph *)malloc(sizeof(Graph));
    graph->numVertices = 0;
    graph->vertices = NULL;
    graph->ratVertex = 0;

    return graph;
}

void addVertex(Graph *graph)
{
    graph->numVertices++;
    graph->vertices = realloc(graph->vertices, graph->numVertices * sizeof(Node *));
    graph->vertices[graph->numVertices - 1] = NULL;
}

void addEdge(Graph *graph, int startVertex, int endVertex)
{
    Node *newNode = (Node *)malloc(sizeof(Node));

    newNode->data = endVertex;
    newNode->forward = NULL;
    newNode->right = NULL;
    newNode->left = NULL;
    newNode->behind = NULL;
    newNode->next = graph->vertices[startVertex];
    graph->vertices[startVertex] = newNode;
}

void printGraph(Graph *graph)
{
    for (int i = 0; i < graph->numVertices; i++)
    {
        Node *current = graph->vertices[i];

        printf("Vertex %d (Connected to): ", i);

        while (current != NULL)
        {
            if (current->right)
                printf("Right ");

            if (current->left)
                printf("Left ");

            if (current->forward)
                printf("Forward ");

            if (current->behind)
                printf("Behind ");

            printf("(%d) -> ", current->data);
            current = current->next;
        }

        printf("NULL\n");
        printf("ratVertex = %d\n", graph->ratVertex);
    }
}

void decimalToBinary(Graph *maze, int decimal)
{
    int binary[4];
    int i = 0;

    while (decimal > 0)
    {
        binary[i] = decimal % 2;
        decimal = decimal / 2;
        i++;
    }

    // Forward
    if (binary[0] == 1)
    {
        addVertex(maze);

        addEdge(maze, maze->ratVertex, maze->numVertices - 1);
        addEdge(maze, maze->numVertices - 1, maze->ratVertex);

        maze->vertices[maze->ratVertex]->forward = maze->vertices[maze->numVertices - 1];
        maze->vertices[maze->numVertices - 1]->behind = maze->vertices[maze->ratVertex];
    }

    // Right
    if (binary[1] == 1)
    {
        addVertex(maze);

        addEdge(maze, maze->ratVertex, maze->numVertices - 1);
        addEdge(maze, maze->numVertices - 1, maze->ratVertex);

        maze->vertices[maze->ratVertex]->right = maze->vertices[maze->numVertices - 1];
        maze->vertices[maze->numVertices - 1]->left = maze->vertices[maze->ratVertex];
    }

    // Left
    if (binary[2] == 1)
    {
        addVertex(maze);

        addEdge(maze, maze->ratVertex, maze->numVertices - 1);
        addEdge(maze, maze->numVertices - 1, maze->ratVertex);

        maze->vertices[maze->ratVertex]->left = maze->vertices[maze->numVertices - 1];
        maze->vertices[maze->numVertices - 1]->right = maze->vertices[maze->ratVertex];
    }

    // Behind
    if (binary[3] == 1)
    {
        addVertex(maze);

        addEdge(maze, maze->ratVertex, maze->numVertices - 1);
        addEdge(maze, maze->numVertices - 1, maze->ratVertex);

        maze->vertices[maze->ratVertex]->behind = maze->vertices[maze->numVertices - 1];
        maze->vertices[maze->numVertices - 1]->forward = maze->vertices[maze->ratVertex];
    }
}



void decision(Graph *maze, int result)
{
    Node *current = maze->vertices[maze->ratVertex];

    // Verificar se pode mover para frente
    if (current->forward != NULL)
    {
        printf("w");
        scanf("%d", &result);

        maze->ratVertex = current->forward->data;
    }

    // Rotacionar para a direita
    else if (current->right != NULL)
    {
        printf("r");
        scanf("%d", &result);

        printf("w");
        scanf("%d", &result);

        maze->ratVertex = current->right->data;

        printf("l");
        scanf("%d", &result);
    }

    // Rotacionar para a esquerda
    else if (current->left != NULL)
    {
        printf("l");
        scanf("%d", &result);

        printf("w");
        scanf("%d", &result);

        maze->ratVertex = current->left->data;

        printf("r");
        scanf("%d", &result);
    }

    else
    {
        printf("r");
        scanf("%d", &result);

        printf("r");
        scanf("%d", &result);

        printf("w");
        scanf("%d", &result);

        maze->ratVertex = current->behind->data;

        printf("l");
        scanf("%d", &result);

        printf("l");
        scanf("%d", &result);
    }
}





int main()
{
    int result;
    Graph *maze = createGraph();

    addVertex(maze);

    printf("c");
    scanf("%d", &result);

    decimalToBinary(maze, result);
    printGraph(maze);

    decision(maze, result);
    printGraph(maze);

    return 0;
}
