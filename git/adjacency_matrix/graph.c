#include "graph.h"

Graph* CreateGraph() {
    Graph *graph = (Graph *)malloc(sizeof(Graph));
    if (graph == NULL) {
        printf("Memory allocation failed for graph\n");
        return NULL;
    }
    graph->vertex_num = 0;
    graph->edge_num = 0;
    int i, j;
    for (i = 0; i < MAX_VERTEX_NUM; i++) {
        strcpy(graph->vertices[i], "");
        for (j = 0; j < MAX_VERTEX_NUM; j++) {
            graph->matrix[i][j] = INF;
        }
        graph->matrix[i][i] = 0;
    }
    return graph;
}

int FindVertexIndex(Graph *graph, const char *name) {
    if (graph == NULL || name == NULL) {
        return -1;
    }
    int i;
    for (i = 0; i < graph->vertex_num; i++) {
        if (strcmp(graph->vertices[i], name) == 0) {
            return i;
        }
    }
    return -1;
}

int AddVertex(Graph *graph, const char *name) {
    if (graph == NULL || name == NULL) {
        printf("Error: Invalid parameter\n");
        return -1;
    }
    if (graph->vertex_num >= MAX_VERTEX_NUM) {
        printf("Error: Vertex number exceeds maximum limit\n");
        return -1;
    }
    if (FindVertexIndex(graph, name) != -1) {
        printf("Error: Vertex '%s' already exists\n", name);
        return -1;
    }
    strcpy(graph->vertices[graph->vertex_num], name);
    graph->vertex_num++;
    return graph->vertex_num - 1;
}

int AddEdge(Graph *graph, const char *v1, const char *v2, int weight) {
    if (graph == NULL || v1 == NULL || v2 == NULL) {
        printf("Error: Invalid parameter\n");
        return -1;
    }
    int i = FindVertexIndex(graph, v1);
    int j = FindVertexIndex(graph, v2);
    if (i == -1) {
        printf("Error: Vertex '%s' not found\n", v1);
        return -1;
    }
    if (j == -1) {
        printf("Error: Vertex '%s' not found\n", v2);
        return -1;
    }
    graph->matrix[i][j] = weight;
    graph->matrix[j][i] = weight;
    graph->edge_num++;
    return 0;
}

void PrintGraph(Graph *graph) {
    if (graph == NULL) {
        printf("Error: Graph is NULL\n");
        return;
    }
    printf("========================================\n");
    printf("景区路径规划图（邻接矩阵存储）\n");
    printf("========================================\n");
    printf("景点总数: %d\n", graph->vertex_num);
    printf("路径总数: %d\n", graph->edge_num);
    printf("----------------------------------------\n");
    printf("景点间路径关系:\n");
    int i, j;
    for (i = 0; i < graph->vertex_num; i++) {
        printf("%s:", graph->vertices[i]);
        int has_edge = 0;
        for (j = 0; j < graph->vertex_num; j++) {
            if (i != j && graph->matrix[i][j] != INF) {
                if (has_edge) {
                    printf(",");
                }
                printf(" %s(%dm)", graph->vertices[j], graph->matrix[i][j]);
                has_edge = 1;
            }
        }
        printf("\n");
    }
    printf("========================================\n");
}

void PrintAdjacencyMatrix(Graph *graph) {
    if (graph == NULL) {
        printf("Error: Graph is NULL\n");
        return;
    }
    printf("========================================\n");
    printf("邻接矩阵详细结构\n");
    printf("========================================\n");
    printf("        ");
    int i, j;
    for (i = 0; i < graph->vertex_num; i++) {
        printf("%-8s", graph->vertices[i]);
    }
    printf("\n");
    for (i = 0; i < graph->vertex_num; i++) {
        printf("%-8s", graph->vertices[i]);
        for (j = 0; j < graph->vertex_num; j++) {
            if (graph->matrix[i][j] == INF) {
                printf("%-8s", "-");
            } else {
                printf("%-8d", graph->matrix[i][j]);
            }
        }
        printf("\n");
    }
    printf("========================================\n");
    printf("注: '-' 表示无边连接，数值表示路径距离(米)\n");
    printf("========================================\n");
}

void DestroyGraph(Graph *graph) {
    if (graph == NULL) {
        return;
    }
    free(graph);
}
