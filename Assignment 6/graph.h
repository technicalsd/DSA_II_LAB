#ifndef GRAPH_H
#define GRAPH_H

#define MAX_VERTICES 100

typedef struct {
    int adjacency_matrix[MAX_VERTICES][MAX_VERTICES];
    int num_vertices;
} Graph;

Graph* create_graph(int num_vertices);
void initialize_graph(Graph* graph);
void read_graph_from_file(Graph* graph, const char* filename);
void display_graph(const Graph* graph);
void display_vertex_degrees(const Graph* graph);
int is_connected(const Graph* graph);
void depth_first_search(const Graph* graph, int vertex, int* visited);
void find_components(const Graph* graph);
int are_adjacent(const Graph* graph, int vertex1, int vertex2);

#endif