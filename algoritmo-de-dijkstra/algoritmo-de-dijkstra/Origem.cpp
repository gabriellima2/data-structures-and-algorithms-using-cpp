#include <iostream>;
using namespace std;

#define total_vertices 4
#define total_edges 4

// Inicializa com INT_MAX, pois � uma estimativa, ent�o jogamos um valor alto.

// Indice do vértice que tem a menor distância até a origem entre os que ainda não foram visitados.
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

	// Inicializar as vari�veis
	for (int index = 0; index < total_vertices; index++)
	{
		shorter_distances[index] = INT_MAX;
		vertices_already_visited[index] = false;
	}

	// A dist�ncia da v�rtice inicial para ela mesma � 0.
	shorter_distances[source_vertex] = 0;

	for (int current_vertex = 0; current_vertex < total_vertices - 1; current_vertex++)
	{
		int min_distance_index = get_min_distance(shorter_distances, vertices_already_visited);
		vertices_already_visited[min_distance_index] = true;

		// Atualizar as dist�ncias baseado nas distâncias dos vértices adjacentes ao vértice visitado
		for (int current_edge_index = 0; current_edge_index < total_edges; current_edge_index++)
		{
			int const shortest_distance_already_found = shorter_distances[min_distance_index];
			int const shortest_distance_current_vertex = graph[min_distance_index][current_edge_index];

			// A soma dos pesos das arestas e se for o menor vai ser o peso do caminho de uma v�rtice � outra. (Linha do array � outra)
			int const current_shortest_distance = shortest_distance_already_found + shortest_distance_current_vertex;

			// se o vértice adjacente não foi visitado,
			// se existe uma aresta entre os dois vértices,
			// se a distância até o vértice visitado não é infinita e
			// se a soma das distâncias é menor do que a distância atual.
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
	// Representa��o de um grafo usando um array de adjac�ncia. 0 === Sem aresta.
	int graph[total_vertices][total_edges] = {
		{ 0, 4, 0, 0 }, // 0
		{ 4, 0, 2, 0 }, // (V�rtice Adjacente) 4: 0(Peso da aresta da v�rtice anterior) + 4 (Peso da aresta que 'conecta' a v�rtice anterior com essa, que resultou na menor dist�ncia)
		{ 0, 8, 0, 2 }, // (V�rtice Adjacente) 6: 4(Peso da aresta da v�rtice anterior) + 2 (Peso da aresta que 'conecta' a v�rtice anterior com essa, que resultou na menor dist�ncia)
		{ 0, 0, 7, 0 }, // (V�rtice Adjacente) 8: 6(Peso da aresta da v�rtice anterior) + 2 (Peso da aresta que 'conecta' a v�rtice anterior com essa, que resultou na menor dist�ncia)
	};
	dijkstra(graph, 0);
	return 0;
}
