#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

int main(int argc, char* argv[]) {
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    printf("\n===== Graph Operations =====\n");

    Graph* graph = create_graph(MAX_VERTICES);
    read_graph_from_file(graph, argv[1]);

    printf("\n===== Graph Representation =====\n");
    display_graph(graph);

    printf("\n===== Vertex Degrees =====\n");
    display_vertex_degrees(graph);

    printf("\n===== Connectivity Check =====\n");
    is_connected(graph);

    int vertex1 = 2, vertex2 = 3;
    printf("\n===== Adjacency Check =====\n");
    are_adjacent(graph, vertex1, vertex2);

    printf("\n===== Connected Components =====\n");
    find_components(graph);

    printf("\n===== Done! =====\n");

    free(graph);

    return 0;
}