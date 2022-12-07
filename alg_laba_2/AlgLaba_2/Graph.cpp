#include "Graph.h"

Graph::Graph(): size(0), matrix(nullptr) {}

Graph::Graph(int size): size(size)
{
	int** matrix = new int*[size];
	for (size_t i = 0; i < size; ++i)
		matrix[i] = new int[size];

	for (size_t i = 0; i < size; ++i)
		for (size_t j = 0; j < size; ++j)
			matrix[i][j] = 0;
}

Graph::Graph(int size, int** matrix) : size(size)
{

	this->matrix = new int* [size];
	for (size_t i = 0; i < size; ++i)
		this->matrix[i] = new int[size];

	for (size_t i = 0; i < size; ++i)
		for (size_t j = 0; j < size; ++j)
			this->matrix[i][j] = matrix[i][j];
}

Graph::Graph(const Graph& tmp)
{
	size = tmp.size;
	matrix = new int* [size];
	for (size_t i = 0; i < size; ++i)
		matrix[i] = new int[size];
	
	for (size_t i = 0; i < size; ++i)
		for (size_t j = 0; j < size; j++)
			matrix[i][j] = tmp.matrix[i][j];
}

Graph::~Graph()
{
	for (size_t i = 0; i < size; ++i)
		delete[] matrix[i];
	delete[] matrix;
}

Graph& Graph::operator=(const Graph& tmp)
{
	if (this == &tmp)
		return *this;
	else
	{
		if (matrix)
		{
			for (size_t i = 0; i < size; ++i)
				delete[] matrix[i];
			delete[] matrix;
		}
			
		for (size_t i = 0; i < size; ++i)
			matrix[i] = new int[size];

		for (size_t i = 0; i < size; ++i)
			for (size_t j = 0; j < size; j++)
				matrix[i][j] = tmp.matrix[i][j];
		return *this;
	}
}

void Graph::add_edge(int i, int j)
{
	--i; --j;
	if (i < size && j < size && i > -1 && j > -1)
	{
		matrix[i][j] = 1;
		matrix[j][i] = 1;
	}

}

void Graph::remove_edge(int i, int j)
{
	if (i < size && j < size && i > -1 && j > -1)
		matrix[i][j] = 0;
}

void Graph::add_vertex(int n)
{
	int** tmparr = new int* [size];
	for (size_t i = 0; i < size; ++i)
		tmparr[i] = new int[size];

	for (size_t i = 0; i < size; ++i)
		for (size_t j = 0; j < size; ++j)
			tmparr[i][j] = matrix[i][j];

	for (size_t i = 0; i < size; ++i)
		delete[] matrix[i];
	delete[] matrix;

	size += n;
	int** matrix = new int* [size];
	for (size_t i = 0; i < size; ++i)
		matrix[i] = new int[size];

	for (size_t i = 0; i < size-n; ++i)
		for (size_t j = 0; j < size-n; ++j)
			matrix[i][j] = tmparr[i][j];

	for (size_t i = size - n; i < size; ++i)
		for (size_t j = size - n; j < size; ++j)
			matrix[i][j] = 0;
}

void Graph::remove_vertex(int n)
{
	int** tmparr = new int* [size];
	for (size_t i = 0; i < size; ++i)
		tmparr[i] = new int[size];

	for (size_t i = 0; i < size; ++i)
		for (size_t j = 0; j < size; ++j)
			tmparr[i][j] = matrix[i][j];

	for (size_t i = 0; i < size; ++i)
		delete[] matrix[i];
	delete[] matrix;

	size -= n;
	int** matrix = new int* [size];
	for (size_t i = 0; i < size; ++i)
		matrix[i] = new int[size];

	for (size_t i = 0; i < size; ++i)
		for (size_t j = 0; j < size; ++j)
			matrix[i][j] = tmparr[i][j];
}

bool Graph::is_edge(int i, int j)
{
	return matrix[i][j];
}

int Graph::get_size()
{
	return size;
}

int** Graph::get_matrix()
{
	return matrix;
}

std::ostream& operator<<(std::ostream& out, const Graph& tmp)
{

	out << "  ";
	for (size_t i = 1; i <= tmp.size; ++i)
		out << '_' << i;
	out << '_';
	out << '\n';
	for (size_t i = 0; i < tmp.size; ++i)
	{
		out << i + 1 << "| ";
		for (size_t j = 0; j < tmp.size; ++j)
			out << tmp.matrix[i][j] << ' ';
		out << '\n';
	}
	return out;
}
