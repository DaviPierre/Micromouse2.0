#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node
{

    int data;
    int x;
    int y;
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

void addVertex(Graph *maze)
{
    maze->numVertices++;
    maze->vertices = realloc(maze->vertices, maze->numVertices * sizeof(Node *));
    maze->vertices[maze->numVertices - 1] = NULL;
}

void addEdge(Graph *maze, int startVertex, int endVertex)
{
    Node *newNode = (Node *)malloc(sizeof(Node));

    newNode->data = endVertex;
    newNode->forward = NULL;
    newNode->right = NULL;
    newNode->left = NULL;
    newNode->behind = NULL;
    newNode->x = 0;
    newNode->y = 0;
    newNode->next = maze->vertices[startVertex];
    maze->vertices[startVertex] = newNode;
}

void printGraph(Graph *maze)
{
    for (int i = 0; i < maze->numVertices; i++)
    {
        Node *current = maze->vertices[i];

        printf("\n VEREDICT X = %d \n VEREDICT Y = %d\n", current->x, current->y);

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

    printf("ratVertex = %d\n", maze->ratVertex);
    printf("numRotations = %d\n", maze->numRotations);
}

// ---- FIM DAS FUNÇÕES DE CRIAÇÃO DE GRAFOS ----

// ---- COMEÇO DA LÓGICA DO LABIRINTO ----

void verifyCicle(Graph *maze, char action)
{


    for (int i = 0; i < maze->numVertices; i++)
    {
        switch (action)
        {
        case 'F':
            maze->vertices[i]->x++;
            break;

        case 'R':
            maze->vertices[i]->y++;
            break;

        case 'B':
            maze->vertices[i]->x--;
            break;

        case 'L':
            maze->vertices[i]->y--;
            break;
        }

        if (maze->vertices[i]->x == 0 && maze->vertices[i]->y == 0)
        {

            switch (action)
            {
            case 'F':
                
                maze->vertices[maze->ratVertex]->forward = maze->vertices[maze->vertices[i]->data];
                maze->vertices[maze->vertices[i]->data]->behind = maze->vertices[maze->ratVertex];
                maze->ratVertex = i;
                // destroyNode(maze, maze->vertices[maze->numVertices - 1]);
                break;

            case 'R':
                maze->vertices[maze->ratVertex]->right = maze->vertices[maze->vertices[i]->data];
                maze->vertices[maze->vertices[i]->data]->left = maze->vertices[maze->ratVertex];
                maze->ratVertex = i;
                // destroyNode(maze, maze->vertices[maze->numVertices - 1]);
                break;

            case 'B':
                maze->vertices[maze->ratVertex]->behind = maze->vertices[maze->vertices[i]->data];
                maze->vertices[maze->vertices[i]->data]->forward = maze->vertices[maze->ratVertex];
                maze->ratVertex = i;
                // destroyNode(maze, maze->vertices[maze->numVertices - 1]);
                break;

            case 'L':
                maze->vertices[maze->vertices[maze->ratVertex]->right->data]->left = NULL;
                free(maze->vertices[maze->vertices[maze->ratVertex]->right->data]);
                maze->numVertices--;
                maze->vertices[maze->ratVertex]->right = NULL;

                maze->vertices[maze->ratVertex]->left = maze->vertices[maze->vertices[i]->data];
                maze->vertices[maze->vertices[i]->data]->right = maze->vertices[maze->ratVertex];
                maze->ratVertex = i;
                break;

            }
        }
    }
}



// ---- FIM DA LÓGICA DO LABIRINTO ----

// ---- COMEÇO DAS FUNÇÕES DE MOVIMENTAÇÃO DO RATO ----
int onwardFoward(Graph *maze)
{
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

        verifyCicle(maze, 'F');
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

int onwardRight(Graph *maze)
{
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


        verifyCicle(maze, 'R');
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

int onwardBehind(Graph *maze)
{
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

        verifyCicle(maze, 'B');
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

int onwardLeft(Graph *maze)
{
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

        verifyCicle(maze, 'L');
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

int rotateRight(Graph *maze)
{
    int result;

    printGraph(maze);

    printf("r");
    scanf("%d", &result);

    maze->numRotations++;
}

int initiateMove(Graph *maze)
{
    int enter = 0, result = 0;
    int rotations = maze->numRotations % 4;

    switch (rotations)
    {

    case 0:

        printf("Tentando andar pra frente\n");
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

            enter = 2;
            verifyCicle(maze, 'F');
            return enter;

            break;

        case 2:

            addVertex(maze);

            addEdge(maze, maze->ratVertex, maze->numVertices - 1);
            addEdge(maze, maze->numVertices - 1, maze->ratVertex);

            maze->vertices[maze->ratVertex]->forward = maze->vertices[maze->numVertices - 1];
            maze->vertices[maze->numVertices - 1]->behind = maze->vertices[maze->ratVertex];

            maze->ratVertex = maze->numVertices - 1;

            enter = 4;
            return enter;

            printf("QUEIJO VAIDO\n");

            break;

        default:
            result = 0;
            break;
        }

        if (result == 0)
        {
            result = rotateRight(maze);
            rotations = maze->numRotations;
            rotations = rotations % 4;
        }

        printGraph(maze);
        printf("ROTATIONS: %d / 4 = %d\n ", maze->numRotations, rotations);

        break;

    case 1:

        printf("Tentativa de andar para direita\n");

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

            enter = 2;
            verifyCicle(maze, 'R');
            return enter;
            break;

        case 2:

            addVertex(maze);

            addEdge(maze, maze->ratVertex, maze->numVertices - 1);
            addEdge(maze, maze->numVertices - 1, maze->ratVertex);

            maze->vertices[maze->ratVertex]->right = maze->vertices[maze->numVertices - 1];
            maze->vertices[maze->numVertices - 1]->left = maze->vertices[maze->ratVertex];

            maze->ratVertex = maze->numVertices - 1;

            enter = 4;
            return enter;
            printf("QUEIJO VAIDO\n");

            break;

        default:
            result = 0;
            break;
        }

        if (result == 0)
        {
            result = rotateRight(maze);
            rotations = maze->numRotations;
            rotations = rotations % 4;
        }

        printGraph(maze);
        printf("ROTATIONS: %d % 4 = %d\n ", maze->numRotations, rotations);

        break;

    case 2:

        printf("Tentativa de andar para traz\n");

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

            enter = 2;
            verifyCicle(maze, 'B');
            return enter;
            break;

        case 2:

            addVertex(maze);

            addEdge(maze, maze->ratVertex, maze->numVertices - 1);
            addEdge(maze, maze->numVertices - 1, maze->ratVertex);

            maze->vertices[maze->ratVertex]->behind = maze->vertices[maze->numVertices - 1];
            maze->vertices[maze->numVertices - 1]->forward = maze->vertices[maze->ratVertex];

            maze->ratVertex = maze->numVertices - 1;

            enter = 4;
            return enter;
            printf("QUEIJO VAIDO\n");

            break;

        default:
            result = 0;
            break;
        }

        if (result == 0)
        {
            result = rotateRight(maze);
            rotations = maze->numRotations;
            rotations = rotations % 4;
        }

        printGraph(maze);
        printf("ROTATIONS: %d % 4 = %d\n ", maze->numRotations, rotations);

        break;

    case 3:

        printf("Tentativa de ir para esquerda\n");

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

            enter = 2;
            verifyCicle(maze, 'L');
            return enter;
            break;

        case 2:

            addVertex(maze);

            addEdge(maze, maze->ratVertex, maze->numVertices - 1);
            addEdge(maze, maze->numVertices - 1, maze->ratVertex);

            maze->vertices[maze->ratVertex]->left = maze->vertices[maze->numVertices - 1];
            maze->vertices[maze->numVertices - 1]->right = maze->vertices[maze->ratVertex];

            maze->ratVertex = maze->numVertices - 1;

            enter = 4;
            return enter;
            printf("QUEIJO VAIDO\n");

            break;

        default:
            result = 0;
            break;
        }

        if (result == 0)
        {
            result = rotateRight(maze);
            rotations = maze->numRotations;
            rotations = rotations % 4;
        }

        printGraph(maze);
        printf("ROTATIONS: %d % 4 = %d\n ", maze->numRotations, rotations);

        break;
    }
}

// ---- FIM DAS FUNÇÕES DE MOVIMENTAÇÃO DO RATO ----

int main()
{
    int result = 1, rotations = 0, enter = 0;
    Graph *maze = createGraph();
    addVertex(maze);

    while (enter != 2 && enter != 4)
    {

        enter = initiateMove(maze);
        printGraph(maze);
    }

    if (enter == 4)
    {
        result = 2;
    }

    while (result != 2)
    {
        rotations = maze->numRotations % 4;

        switch (rotations)
        {

        case 0:

            printf("Chamou a função onwardFoward!\n");
            result = onwardFoward(maze);

            if (result == 0)
            {
                result = rotateRight(maze);
                rotations = maze->numRotations;
                rotations = rotations % 4;
            }

            printGraph(maze);
            printf("ROTATIONS: %d % 4 = %d\n ", maze->numRotations, rotations);

            break;

        case 1:

            printf("Chamou a função onwardRight!\n");
            result = onwardRight(maze);

            if (result == 0)
            {
                result = rotateRight(maze);
                rotations = maze->numRotations;
                rotations = rotations % 4;
            }

            printGraph(maze);
            printf("ROTATIONS: %d % 4 = %d\n ", maze->numRotations, rotations);

            break;

        case 2:

            printf("Chamou a função onwardBehind!\n");
            result = onwardBehind(maze);

            if (result == 0)
            {
                result = rotateRight(maze);
                rotations = maze->numRotations;
                rotations = rotations % 4;
            }

            printGraph(maze);
            printf("ROTATIONS: %d % 4 = %d\n ", maze->numRotations, rotations);

            break;

        case 3:

            printf("Chamou a função onwardLeft!\n");
            result = onwardLeft(maze);

            if (result == 0)
            {
                result = rotateRight(maze);
                rotations = maze->numRotations;
                rotations = rotations % 4;
            }

            printGraph(maze);
            printf("ROTATIONS: %d % 4 = %d\n ", maze->numRotations, rotations);

            break;
        }
    }

    return 0;
}