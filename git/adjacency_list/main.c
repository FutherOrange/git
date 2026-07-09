#include "graph.h"

int main() {
    printf("========================================\n");
    printf("景区路径规划图系统 - 邻接表实现\n");
    printf("========================================\n\n");

    Graph *graph = CreateGraph();
    if (graph == NULL) {
        return -1;
    }

    printf("【阶段1】添加景区景点顶点\n");
    AddVertex(graph, "大门");
    AddVertex(graph, "湖心亭");
    AddVertex(graph, "植物园");
    AddVertex(graph, "山顶塔");
    AddVertex(graph, "瀑布");
    AddVertex(graph, "儿童乐园");
    printf("已添加 %d 个景点\n\n", graph->vertex_num);

    printf("【阶段2】添加景点间路径边\n");
    AddEdge(graph, "大门", "湖心亭", 200);
    AddEdge(graph, "大门", "植物园", 150);
    AddEdge(graph, "湖心亭", "山顶塔", 500);
    AddEdge(graph, "湖心亭", "瀑布", 300);
    AddEdge(graph, "植物园", "瀑布", 250);
    AddEdge(graph, "山顶塔", "瀑布", 180);
    AddEdge(graph, "瀑布", "儿童乐园", 220);
    AddEdge(graph, "植物园", "儿童乐园", 350);
    printf("已添加 %d 条路径\n\n", graph->edge_num);

    printf("【阶段3】打印完整景区图\n");
    PrintGraph(graph);
    printf("\n");

    printf("【阶段4】打印邻接表明细\n");
    PrintAdjacencyList(graph);
    printf("\n");

    DestroyGraph(graph);

    printf("程序执行完毕！\n");
    return 0;
}
