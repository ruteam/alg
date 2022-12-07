#pragma once
#include <iostream>
class Graph
{
	int size;
	int** matrix;
public:
	Graph();
	Graph(int size);
	Graph(int size, int** matrix);
	Graph(const Graph& tmp);
	~Graph();
	Graph& operator=(const Graph& tmp);
	void add_edge(int i, int j);
	void remove_edge(int i, int j);
	void add_vertex(int n);
	void remove_vertex(int n);
	bool is_edge(int i, int j);
	int get_vertex();
	int get_size();
	int** get_matrix();
	friend std::ostream& operator <<(std::ostream& out, const Graph& tmp);
};

