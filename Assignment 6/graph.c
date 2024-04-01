#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

Graph* create_graph(int num_vertices) {
    printf("\nCreating a new graph with %d vertices...\n", num_vertices);
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->num_vertices = num_vertices;
    initialize_graph(graph);
    return graph;
}

void initialize_graph(Graph* graph) {
    printf("Initializing the graph...\n");
    for (int i = 0; i < graph->num_vertices; i++) {
        for (int j = 0; j < graph->num_vertices; j++) {
            graph->adjacency_matrix[i][j] = 0;
        }
    }
    printf("Graph initialized successfully!\n");
}

void read_graph_from_file(Graph* graph, const char* filename) {
    printf("\nReading graph data from file: %s\n", filename);
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: Unable to open the file.\n");
        return;
    }

    fscanf(file, "%d", &graph->num_vertices);
    printf("Number of vertices: %d\n", graph->num_vertices);

    int u, v, weight;
    while (fscanf(file, "%d %d %d", &u, &v, &weight) == 3) {
        graph->adjacency_matrix[u][v] = weight;
        graph->adjacency_matrix[v][u] = weight;
        printf("Added edge: %d -- %d (weight: %d)\n", u, v, weight);
    }

    fclose(file);
    printf("Graph data read successfully!\n");
}

void display_graph(const Graph* graph) {
    printf("\nAdjacency Matrix:\n");
    for (int i = 0; i < graph->num_vertices; i++) {
        for (int j = 0; j < graph->num_vertices; j++) {
            printf("%d ", graph->adjacency_matrix[i][j]);
        }
        printf("\n");
    }
}

void display_vertex_degrees(const Graph* graph) {
    printf("\nVertex Degrees:\n");
    for (int i = 0; i < graph->num_vertices; i++) {
        int degree = 0;
        for (int j = 0; j < graph->num_vertices; j++) {
            degree += graph->adjacency_matrix[i][j];
        }
        printf("Vertex %d: %d\n", i, degree);
    }
}

int is_connected(const Graph* graph) {
    printf("\nChecking if the graph is connected...\n");
    int visited[MAX_VERTICES] = { 0 };
    depth_first_search(graph, 0, visited);

    for (int i = 0; i < graph->num_vertices; i++) {
        if (visited[i] == 0) {
            printf("The graph is not connected.\n");
            return 0;
        }
    }
    printf("The graph is connected!\n");
    return 1;
}

void depth_first_search(const Graph* graph, int vertex, int* visited) {
    visited[vertex] = 1;
    printf("Visited vertex: %d\n", vertex);
    for (int i = 0; i < graph->num_vertices; i++) {
        if (graph->adjacency_matrix[vertex][i] && !visited[i]) {
            depth_first_search(graph, i, visited);
        }
    }
}

void find_components(const Graph* graph) {
    printf("\nFinding connected components...\n");
    int visited[MAX_VERTICES] = { 0 };
    int component_count = 0;

    for (int i = 0; i < graph->num_vertices; i++) {
        if (!visited[i]) {
            component_count++;
            printf("\nComponent %d:\n", component_count);
            depth_first_search(graph, i, visited);
            printf("Vertices: ");
            for (int j = 0; j < graph->num_vertices; j++) {
                if (visited[j]) {
                    printf("%d ", j);
                    visited[j] = 0;
                }
            }
            printf("\n");
        }
    }
}

int are_adjacent(const Graph* graph, int vertex1, int vertex2) {
    if (graph->adjacency_matrix[vertex1][vertex2]) {
        printf("Vertices %d and %d are adjacent.\n", vertex1, vertex2);
        return 1;
    } else {
        printf("Vertices %d and %d are not adjacent.\n", vertex1, vertex2);
        return 0;
    }
}