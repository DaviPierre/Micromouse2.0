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

// ---- FIM DAS FUNÇÕES DE CRIAÇÃO DE GRAFOS ----

// ---- COMEÇO DA LÓGICA DO LABIRINTO ----

int verifyCicle(Graph *maze, char action)
{
    for (int i = 0; i < maze->numVertices; i++)
    {
        bool veredict_x = false;
        bool veredict_y = false;

        switch (action)
        {
        case 'F':
            maze->vertices[i]->x++;
            if (maze->vertices[i]->x == 0)
                veredict_x = true;
            break;

        case 'R':
            maze->vertices[i]->y++;
            if (maze->vertices[i]->y == 0)
                veredict_y = true;
            break;

        case 'B':
            maze->vertices[i]->x--;
            if (maze->vertices[i]->x == 0)
                veredict_x = true;
            break;

        case 'L':
            maze->vertices[i]->y--;
            if (maze->vertices[i]->y == 0)
                veredict_y = true;
            break;

        default:
            // Handle the default case
            veredict_x = false;
            veredict_y = false;
            break;
        }

        if (veredict_x && veredict_y)
        {
            return maze->vertices[i]->data;
        }
    }

    return 1000000000;
}

// ---- FIM DA LÓGICA DO LABIRINTO ----

// ---- COMEÇO DAS FUNÇÕES DE MOVIMENTAÇÃO DO RATO ----
int onwardFoward(Graph *maze)
{
    int result, verify = 1000000000;

    printf("w");
    scanf("%d", &result);

    switch (result)
    {
    case 1:

        verify = verifyCicle(maze, 'F');

        if (verify != 1000000000)
        {

            maze->vertices[maze->ratVertex]->forward = maze->vertices[verify];
            maze->vertices[verify]->behind = maze->vertices[maze->ratVertex];
            maze->ratVertex = verify;
            return result;
        }
        else
        {

            addVertex(maze);

            addEdge(maze, maze->ratVertex, maze->numVertices - 1);
            addEdge(maze, maze->numVertices - 1, maze->ratVertex);

            maze->vertices[maze->ratVertex]->forward = maze->vertices[maze->numVertices - 1];
            maze->vertices[maze->numVertices - 1]->behind = maze->vertices[maze->ratVertex];

            maze->ratVertex = maze->numVertices - 1;
        }
        break;

    case 2:

        verify = verifyCicle(maze, 'F');

        if (verify != 1000000000)
        {

            maze->vertices[maze->ratVertex]->forward = maze->vertices[verify];
            maze->vertices[verify]->behind = maze->vertices[maze->ratVertex];
            maze->ratVertex = verify;
            return result;
        }
        else
        {

            addVertex(maze);

            addEdge(maze, maze->ratVertex, maze->numVertices - 1);
            addEdge(maze, maze->numVertices - 1, maze->ratVertex);

            maze->vertices[maze->ratVertex]->forward = maze->vertices[maze->numVertices - 1];
            maze->vertices[maze->numVertices - 1]->behind = maze->vertices[maze->ratVertex];

            maze->ratVertex = maze->numVertices - 1;
        }

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
    int result, verify;

    printf("w");
    scanf("%d", &result);

    switch (result)
    {
    case 1:

        verify = verifyCicle(maze, 'R');

        if (verify != 1000000000)
        {

            maze->vertices[maze->ratVertex]->right = maze->vertices[verify];
            maze->vertices[verify]->left = maze->vertices[maze->ratVertex];
            maze->ratVertex = verify;
            return result;
        }
        else
        {

            addVertex(maze);

            addEdge(maze, maze->ratVertex, maze->numVertices - 1);
            addEdge(maze, maze->numVertices - 1, maze->ratVertex);

            maze->vertices[maze->ratVertex]->right = maze->vertices[maze->numVertices - 1];
            maze->vertices[maze->numVertices - 1]->left = maze->vertices[maze->ratVertex];

            maze->ratVertex = maze->numVertices - 1;
        }

        break;

    case 2:

        verify = verifyCicle(maze, 'F');

        if (verify != 1000000000)
        {

            maze->vertices[maze->ratVertex]->right = maze->vertices[verify];
            maze->vertices[verify]->left = maze->vertices[maze->ratVertex];
            maze->ratVertex = verify;
            return result;
        }
        else
        {

            addVertex(maze);

            addEdge(maze, maze->ratVertex, maze->numVertices - 1);
            addEdge(maze, maze->numVertices - 1, maze->ratVertex);

            maze->vertices[maze->ratVertex]->right = maze->vertices[maze->numVertices - 1];
            maze->vertices[maze->numVertices - 1]->left = maze->vertices[maze->ratVertex];

            maze->ratVertex = maze->numVertices - 1;
        }

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
    int result, verify;

    printf("w");
    scanf("%d", &result);

    switch (result)
    {
    case 1:

        verify = verifyCicle(maze, 'B');

        if (verify != 1000000000)
        {

            maze->vertices[maze->ratVertex]->behind = maze->vertices[verify];
            maze->vertices[verify]->forward = maze->vertices[maze->ratVertex];
            maze->ratVertex = verify;
            return result;
        }
        else
        {

            addVertex(maze);

            addEdge(maze, maze->ratVertex, maze->numVertices - 1);
            addEdge(maze, maze->numVertices - 1, maze->ratVertex);

            maze->vertices[maze->ratVertex]->forward = maze->vertices[maze->numVertices - 1];
            maze->vertices[maze->numVertices - 1]->behind = maze->vertices[maze->ratVertex];

            maze->ratVertex = maze->numVertices - 1;
        }

        break;

    case 2:

        verify = verifyCicle(maze, 'F');

        if (verify != 1000000000)
        {

            maze->vertices[maze->ratVertex]->behind = maze->vertices[verify];
            maze->vertices[verify]->forward = maze->vertices[maze->ratVertex];
            maze->ratVertex = verify;
            return result;
        }
        else
        {

            addVertex(maze);

            addEdge(maze, maze->ratVertex, maze->numVertices - 1);
            addEdge(maze, maze->numVertices - 1, maze->ratVertex);

            maze->vertices[maze->ratVertex]->forward = maze->vertices[maze->numVertices - 1];
            maze->vertices[maze->numVertices - 1]->behind = maze->vertices[maze->ratVertex];

            maze->ratVertex = maze->numVertices - 1;
        }

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
    int result, verify = 1000000000;

    printf("w");
    scanf("%d", &result);

    switch (result)
    {
    case 1:

        verify = verifyCicle(maze, 'L');

        if (verify != 1000000000)
        {

            maze->vertices[maze->ratVertex]->left = maze->vertices[verify];
            maze->vertices[verify]->right = maze->vertices[maze->ratVertex];
            maze->ratVertex = verify;
            return result;
        }
        else
        {

            addVertex(maze);

            addEdge(maze, maze->ratVertex, maze->numVertices - 1);
            addEdge(maze, maze->numVertices - 1, maze->ratVertex);

            maze->vertices[maze->ratVertex]->left = maze->vertices[maze->numVertices - 1];
            maze->vertices[maze->numVertices - 1]->right = maze->vertices[maze->ratVertex];

            maze->ratVertex = maze->numVertices - 1;
        }
        break;

    case 2:

        verify = verifyCicle(maze, 'L');

        if (verify != 1000000000)
        {

            maze->vertices[maze->ratVertex]->left = maze->vertices[verify];
            maze->vertices[verify]->right = maze->vertices[maze->ratVertex];
            maze->ratVertex = verify;
            return result;
        }
        else
        {

            addVertex(maze);

            addEdge(maze, maze->ratVertex, maze->numVertices - 1);
            addEdge(maze, maze->numVertices - 1, maze->ratVertex);

            maze->vertices[maze->ratVertex]->left = maze->vertices[maze->numVertices - 1];
            maze->vertices[maze->numVertices - 1]->right = maze->vertices[maze->ratVertex];

            maze->ratVertex = maze->numVertices - 1;
        }

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

    printf("r");
    scanf("%d", &result);

    maze->numRotations++;

    printGraph(maze);
}

int initiateMove(Graph* maze){
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

            printf("Chamou a função onwardBehind!\n");
            


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

            printf("Chamou a função onwardLeft!\n");



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

    while (enter != 2)
    {

        enter = initiateMove(maze);
        printGraph(maze);
    }

    if(enter == 4){result = 2;}

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