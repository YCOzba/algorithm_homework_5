#ifndef GRAPH_H
#define GRAPH_H

#define MAX_CITIES 20

typedef struct Node {
    int city_id;
    struct Node* next;
} Node;

typedef struct {
    Node* adjacency_list[MAX_CITIES];
    int visited[MAX_CITIES];
    int num_vertices;
} Graph;

Graph* create_graph(int vertices);
void add_edge(Graph* graph, int src, int dest);
void DFS(Graph* graph, int vertex);
void reset_visited(Graph* graph);

#endif