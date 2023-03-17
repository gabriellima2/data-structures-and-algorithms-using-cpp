#include <iostream>;
using namespace std;

#define total_vertices 4
#define total_edges 4

// Pegar o indíce da vértice com menor menor distância.
int get_min_distance(int shorter_distances[], bool vertices_already_visited[])
{
	int min_distance = INT_MAX;
	int min_distance_vertex_index = 0;
	for (int current_vertex = 0; current_vertex < total_vertices; current_vertex++)
	{
		if (!vertices_already_visited[current_vertex] && shorter_distances[current_vertex] <= min_distance)
		{
			min_distance = shorter_distances[current_vertex];
			min_distance_vertex_index = current_vertex;
		}
	}
	return min_distance_vertex_index;
}

void dijkstra(int graph[total_vertices][total_vertices], int source_vertex)
{
	int shorter_distances[total_vertices];
	bool vertices_already_visited[total_vertices];

	// Inicializar as variáveis
	for (int index = 0; index < total_vertices; index++)
	{
		shorter_distances[index] = INT_MAX;
		vertices_already_visited[index] = false;
	}

	// A distância da vértice inicial para ela mesma é 0.
	shorter_distances[source_vertex] = 0;

	for (int current_vertex = 0; current_vertex < total_vertices - 1; current_vertex++)
	{
		int min_distance_index = get_min_distance(shorter_distances, vertices_already_visited);
		vertices_already_visited[min_distance_index] = true;

		// Atualizar as distâncias mais curtas
		for (int current_edge_index = 0; current_edge_index < total_edges; current_edge_index++)
		{
			int const shortest_distance_already_found = shorter_distances[min_distance_index];
			int const shortest_distance_current_vertex = graph[min_distance_index][current_edge_index];

			// A soma dos pesos das arestas e se for o menor vai ser o peso do caminho de uma vértice à outra. (Linha do array à outra)
			int const current_shortest_distance = shortest_distance_already_found + shortest_distance_current_vertex;

			// Atualiza as distâncias minímas somente se não estiver visitada;
			 // Existe uma aresta entre as vértices;
			 // Peso total do caminho atual é o menor já registrado
			if (
				!vertices_already_visited[current_edge_index] &&
				graph[min_distance_index][current_edge_index] &&
				shorter_distances[min_distance_index] != INT_MAX &&
				current_shortest_distance < shorter_distances[current_edge_index])
			{
				shorter_distances[current_edge_index] = current_shortest_distance;
			}
		}
	}
}

int main()
{
	// Representação de um grafo usando um array de adjacência.
	int graph[total_vertices][total_edges] = {
		{ 0, 4, 0, 0 }, // 0 Início
		{ 4, 0, 8, 0 }, // 4
		{ 0, 8, 0, 7 }, // 12: resultado da soma de 4 e 8 da vértice anterior
		{ 0, 0, 7, 0 }, // 19: resultado da soma de 8 e 7 da vértice anterior
	};
	dijkstra(graph, 0);
	return 0;
}
