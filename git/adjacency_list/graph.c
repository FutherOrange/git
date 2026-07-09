#include "graph.h"

Graph* CreateGraph() {
    Graph *graph = (Graph *)malloc(sizeof(Graph));
    if (graph == NULL) {
        printf("Memory allocation failed for graph\n");
        return NULL;
    }
    graph->vertex_num = 0;
    graph->edge_num = 0;
    int i;
    for (i = 0; i < MAX_VERTEX_NUM; i++) {
        strcpy(graph->vertices[i].name, "");
        graph->vertices[i].firstarc = NULL;
    }
    return graph;
}

int FindVertexIndex(Graph *graph, const char *name) {
    if (graph == NULL || name == NULL) {
        return -1;
    }
    int i;
    for (i = 0; i < graph->vertex_num; i++) {
        if (strcmp(graph->vertices[i].name, name) == 0) {
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
    strcpy(graph->vertices[graph->vertex_num].name, name);
    graph->vertices[graph->vertex_num].firstarc = NULL;
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
    EdgeNode *edge = (EdgeNode *)malloc(sizeof(EdgeNode));
    if (edge == NULL) {
        printf("Memory allocation failed for edge\n");
        return -1;
    }
    edge->adjvex = j;
    edge->weight = weight;
    edge->nextarc = graph->vertices[i].firstarc;
    graph->vertices[i].firstarc = edge;

    edge = (EdgeNode *)malloc(sizeof(EdgeNode));
    if (edge == NULL) {
        printf("Memory allocation failed for edge\n");
        return -1;
    }
    edge->adjvex = i;
    edge->weight = weight;
    edge->nextarc = graph->vertices[j].firstarc;
    graph->vertices[j].firstarc = edge;

    graph->edge_num++;
    return 0;
}

void PrintGraph(Graph *graph) {
    if (graph == NULL) {
        printf("Error: Graph is NULL\n");
        return;
    }
    printf("========================================\n");
    printf("景区路径规划图（邻接表存储）\n");
    printf("========================================\n");
    printf("景点总数: %d\n", graph->vertex_num);
    printf("路径总数: %d\n", graph->edge_num);
    printf("----------------------------------------\n");
    printf("景点间路径关系:\n");
    int i;
    for (i = 0; i < graph->vertex_num; i++) {
        printf("%s", graph->vertices[i].name);
        EdgeNode *p = graph->vertices[i].firstarc;
        while (p != NULL) {
            printf(" -> %s (距离:%dm)", graph->vertices[p->adjvex].name, p->weight);
            p = p->nextarc;
        }
        printf("\n");
    }
    printf("========================================\n");
}

void PrintAdjacencyList(Graph *graph) {
    if (graph == NULL) {
        printf("Error: Graph is NULL\n");
        return;
    }
    printf("========================================\n");
    printf("邻接表详细结构\n");
    printf("========================================\n");
    int i;
    for (i = 0; i < graph->vertex_num; i++) {
        printf("[%d] %s -> ", i, graph->vertices[i].name);
        EdgeNode *p = graph->vertices[i].firstarc;
        while (p != NULL) {
            printf("(%d,%d)", p->adjvex, p->weight);
            if (p->nextarc != NULL) {
                printf(" -> ");
            }
            p = p->nextarc;
        }
        printf(" NULL\n");
    }
    printf("========================================\n");
}

void DestroyGraph(Graph *graph) {
    if (graph == NULL) {
        return;
    }
    int i;
    for (i = 0; i < graph->vertex_num; i++) {
        EdgeNode *p = graph->vertices[i].firstarc;
        while (p != NULL) {
            EdgeNode *q = p;
            p = p->nextarc;
            free(q);
        }
    }
    free(graph);
}
