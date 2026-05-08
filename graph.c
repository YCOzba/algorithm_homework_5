#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

Graph* create_graph(int vertices) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->num_vertices = vertices;
    for (int i = 0; i < vertices; i++) {
        graph->adjacency_list[i] = NULL;
        graph->visited[i] = 0;
    }
    return graph;
}

void add_edge(Graph* graph, int src, int dest) {
    // Yönlü graf yapısı (Lojistik rotası)
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->city_id = dest;
    new_node->next = graph->adjacency_list[src];
    graph->adjacency_list[src] = new_node;
}

// Derinlemesine Arama (DFS)
void DFS(Graph* graph, int vertex) {
    graph->visited[vertex] = 1;
    printf("Rota Konumu: Sehir ID %d\n", vertex);

    Node* temp = graph->adjacency_list[vertex];
    while (temp != NULL) {
        int connected_vertex = temp->city_id;
        if (graph->visited[connected_vertex] == 0) {
            DFS(graph, connected_vertex);
        }
        temp = temp->next;
    }
}

void reset_visited(Graph* graph) {
    for (int i = 0; i < graph->num_vertices; i++) {
        graph->visited[i] = 0;
    }
}