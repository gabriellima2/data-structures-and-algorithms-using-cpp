#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/*
	Implementação de um grafo usando uma matriz de adjacência, onde as linhas são
	as vértices e as colunas são arestas.

	0: representa sem conexão entre as vértices.
	1: representa conexão entre as vértices.
*/

typedef void (*cb)(vector<int> vertex);

template <typename T>
class Graph
{
private:
	vector<vector<T>> data;
	int total_vertices;

public:
	Graph(int total_vertices);
	vector<vector<T>> get_data();
	int get_total_vertices();
	void add_edge(int origin_vertex_index, int edge_index);
	void remove_edge(int origin_vertex_index, int edge_index);
	void remove_all_edge(int origin_vertex_index);
	bool has_edge(int origin_vertex_index, int edge_index);
	void breadth_first_search(int origin_vertex_index, cb fun);

};

template <typename T>
Graph<T>::Graph(int total_vertices)
{
	this->total_vertices = total_vertices;
	this->data.resize(total_vertices);
	for (int i = 0; i < total_vertices; i++)
	{
		this->data[i].resize(total_vertices);
	}
}

template <typename T>
vector<vector<T>> Graph<T>::get_data()
{
	return this->data;
}

template <typename T>
int Graph<T>::get_total_vertices()
{
	return this->total_vertices;
}

template <typename T>
bool Graph<T>::has_edge(int origin_vertex_index, int edge_index)
{
	const int path = this->data[origin_vertex_index][edge_index];
	return path != 0;
}

template <typename T>
void Graph<T>::add_edge(int origin_vertex_index, int edge_index)
{
	if (this->has_edge(origin_vertex_index, edge_index)) return;
	this->data[origin_vertex_index][edge_index] = 1;
}

template <typename T>
void Graph<T>::remove_edge(int origin_vertex_index, int edge_index)
{
	if (this->has_edge(origin_vertex_index, edge_index)) return;
	this->data[origin_vertex_index][edge_index] = 0;
}

template <typename T>
void Graph<T>::remove_all_edge(int origin_vertex_index)
{
	const int length = this->data[origin_vertex_index].size();
	for (int i = 0; i < length; i++) {
		this->data[origin_vertex_index][i] = 0;
	}
}

// Para caminhar em todas as vértices adjacentes.
template <typename T>
void Graph<T>::breadth_first_search(int origin_vertex_index, cb fun)
{
	vector<bool> visited(this->total_vertices);
	queue<int> queue;
	queue.push(origin_vertex_index);
	visited[origin_vertex_index] = true;

	while (!queue.empty())
	{
		int vertex_index = queue.front();
		queue.pop();
		fun(this->data[vertex_index]);
		// Caminha nas arestas de saida do vértice atual.
		for (int edge_index = 0; edge_index < this->total_vertices; edge_index++)
		{
			// Se tiver uma aresta entre as vértices e não foi visita, marcamos como visitada
			// e adicionamos na fila para a próxima iteração
			if (this->has_edge(vertex_index, edge_index) && !visited[edge_index])
			{
				queue.push(edge_index);
				visited[edge_index] = true;
			}
		}
	}
}

template <typename T>
void log_vertex(vector<T> vertex)
{
	cout << endl;
	for (int i = 0; i < vertex.size(); i++)
	{
		cout << vertex[i] << " ";
	}
}

int main()
{
	Graph<int> cities(5);
	vector<vector<int>> data = cities.get_data();
	cities.add_edge(0, 1);
	cities.add_edge(1, 2);
	cities.breadth_first_search(2, log_vertex);
	return 0;
}
