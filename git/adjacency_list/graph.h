#ifndef GRAPH_H
#define GRAPH_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VERTEX_NAME 50
#define MAX_VERTEX_NUM 20

typedef struct EdgeNode {
    int adjvex;
    int weight;
    struct EdgeNode *nextarc;
} EdgeNode;

typedef struct VertexNode {
    char name[MAX_VERTEX_NAME];
    EdgeNode *firstarc;
} VertexNode;

typedef struct {
    VertexNode vertices[MAX_VERTEX_NUM];
    int vertex_num;
    int edge_num;
} Graph;

Graph* CreateGraph();
int AddVertex(Graph *graph, const char *name);
int AddEdge(Graph *graph, const char *v1, const char *v2, int weight);
void PrintGraph(Graph *graph);
void PrintAdjacencyList(Graph *graph);
void DestroyGraph(Graph *graph);
int FindVertexIndex(Graph *graph, const char *name);

#endif
