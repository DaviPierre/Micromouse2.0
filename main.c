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
    int numRotations;

} Graph;

// ---- COMEÇO DAS FUNÇÕES DE CRIAÇÃO DE GRAFOS ----

Graph *createGraph()
{
    Graph *graph = (Graph *)malloc(sizeof(Graph));
    graph->numVertices = 0;
    graph->vertices = NULL;
    graph->ratVertex = 0;
    graph->numRotations = 0;

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

    }

    printf("ratVertex = %d\n", graph->ratVertex);
    printf("numRotations = %d\n", graph->numRotations);
}

// ---- FIM DAS FUNÇÕES DE CRIAÇÃO DE GRAFOS

// ---- COMEÇO DAS FUNÇÕES DE MOVIMENTAÇÃO DO RATO ----
int onwardFoward(Graph* maze){
    int result;

    printf("w");
    scanf("%d", &result);

    switch (result)
    {
    case 1:

        addVertex(maze);

        addEdge(maze, maze->ratVertex, maze->numVertices - 1);
        addEdge(maze, maze->numVertices - 1, maze->ratVertex);

        maze->vertices[maze->ratVertex]->forward = maze->vertices[maze->numVertices - 1];
        maze->vertices[maze->numVertices - 1]->behind = maze->vertices[maze->ratVertex];
        
        maze->ratVertex = maze->numVertices - 1;

        break;
    
    case 2:

        addVertex(maze);

        addEdge(maze, maze->ratVertex, maze->numVertices - 1);
        addEdge(maze, maze->numVertices - 1, maze->ratVertex);

        maze->vertices[maze->ratVertex]->forward = maze->vertices[maze->numVertices - 1];
        maze->vertices[maze->numVertices - 1]->behind = maze->vertices[maze->ratVertex];
        
        maze->ratVertex = maze->numVertices - 1;

        printf("QUEIJO VAIDO\n");

        break;

    default:
        result = 0;
        break;
    }

    return result;
}

int onwardRight(Graph* maze){
    int result;

    printf("w");
    scanf("%d", &result);

    switch (result)
    {
    case 1:

        addVertex(maze);

        addEdge(maze, maze->ratVertex, maze->numVertices - 1);
        addEdge(maze, maze->numVertices - 1, maze->ratVertex);

        maze->vertices[maze->ratVertex]->right = maze->vertices[maze->numVertices - 1];
        maze->vertices[maze->numVertices - 1]->left = maze->vertices[maze->ratVertex];
        
        maze->ratVertex = maze->numVertices - 1;

        break;
    
    case 2:

        addVertex(maze);

        addEdge(maze, maze->ratVertex, maze->numVertices - 1);
        addEdge(maze, maze->numVertices - 1, maze->ratVertex);

        maze->vertices[maze->ratVertex]->right = maze->vertices[maze->numVertices - 1];
        maze->vertices[maze->numVertices - 1]->left = maze->vertices[maze->ratVertex];
        
        maze->ratVertex = maze->numVertices - 1;

        printf("QUEIJO VAIDO\n");

        break;

    default:
        result = 0;
        break;
    }

    return result;
}

int onwardBehind(Graph* maze){
    int result;

    printf("w");
    scanf("%d", &result);

    switch (result)
    {
    case 1:

        addVertex(maze);

        addEdge(maze, maze->ratVertex, maze->numVertices - 1);
        addEdge(maze, maze->numVertices - 1, maze->ratVertex);

        maze->vertices[maze->ratVertex]->behind = maze->vertices[maze->numVertices - 1];
        maze->vertices[maze->numVertices - 1]->forward = maze->vertices[maze->ratVertex];
        
        maze->ratVertex = maze->numVertices - 1;

        break;
    
    case 2:

        addVertex(maze);

        addEdge(maze, maze->ratVertex, maze->numVertices - 1);
        addEdge(maze, maze->numVertices - 1, maze->ratVertex);

        maze->vertices[maze->ratVertex]->behind = maze->vertices[maze->numVertices - 1];
        maze->vertices[maze->numVertices - 1]->forward = maze->vertices[maze->ratVertex];
        
        maze->ratVertex = maze->numVertices - 1;

        printf("QUEIJO VAIDO\n");

        break;

    default:
        result = 0;
        break;
    }

    return result;
}

int onwardLeft(Graph* maze){
    int result;

    printf("w");
    scanf("%d", &result);

    switch (result)
    {
    case 1:

        addVertex(maze);

        addEdge(maze, maze->ratVertex, maze->numVertices - 1);
        addEdge(maze, maze->numVertices - 1, maze->ratVertex);

        maze->vertices[maze->ratVertex]->left = maze->vertices[maze->numVertices - 1];
        maze->vertices[maze->numVertices - 1]->right = maze->vertices[maze->ratVertex];
        
        maze->ratVertex = maze->numVertices - 1;

        break;
    
    case 2:

        addVertex(maze);

        addEdge(maze, maze->ratVertex, maze->numVertices - 1);
        addEdge(maze, maze->numVertices - 1, maze->ratVertex);

        maze->vertices[maze->ratVertex]->left = maze->vertices[maze->numVertices - 1];
        maze->vertices[maze->numVertices - 1]->right = maze->vertices[maze->ratVertex];
        
        maze->ratVertex = maze->numVertices - 1;

        printf("QUEIJO VAIDO\n");

        break;

    default:
        result = 0;
        break;
    }

    return result;
}

int rotateRight(Graph * maze){
    int result;

    printf("r");
    scanf("%d", &result);

    maze->numRotations++;

    printGraph(maze);

}

// ---- FIM DAS FUNÇÕES DE MOVIMENTAÇÃO DO RATO ----

int main()
{
    int result = 1, rotations = 0;
    Graph *maze = createGraph();

    addVertex(maze);

    while(result != 2){

        switch (rotations)
        {

        case 0:

            printf("Chamou a função onwardFoward!\n");
            result = onwardFoward(maze);

            printGraph(maze);
            
            if(result == 0){
                result = rotateRight(maze);
                rotations = maze->numRotations;
                rotations = rotations % 4;
            }

            printf("ROTATIONS: %d % 4 = %d\n ", maze->numRotations, rotations);

            break;
        
        case 1:

            printf("Chamou a função onwardRight!\n");
            result = onwardRight(maze);

            printGraph(maze);
            
            if(result == 0){
                result = rotateRight(maze);
                rotations = maze->numRotations;
                rotations = rotations % 4;
            }
            printf("ROTATIONS: %d % 4 = %d\n ", maze->numRotations, rotations);

            break;

        case 2:

            printf("Chamou a função onwardBehind!\n");
            result = onwardBehind(maze);

            printGraph(maze);
            
            if(result == 0){
                result = rotateRight(maze);
                rotations = maze->numRotations;
                rotations = rotations % 4;
            }
            printf("ROTATIONS: %d % 4 = %d\n ", maze->numRotations, rotations);

            break;

        case 3:

            printf("Chamou a função onwardLeft!\n");
            result = onwardLeft(maze);

            printGraph(maze);
            
            if(result == 0){
                result = rotateRight(maze);
                rotations = maze->numRotations;
                rotations = rotations % 4;
            }
            printf("ROTATIONS: %d % 4 = %d\n ", maze->numRotations, rotations);

            break;
        }

        

    }



    return 0;
}
