#include <iostream>
#include <queue>
#include <map>
#include <vector>
#include "Graph.h"
using namespace std;

//int find_min(vector<int> board, int n, int k)
//{
//	int result = -1;
//
//	map<vector<int>, int> m;
//	vector<int> sort_board;
//
//	for (size_t i = 0; i < n; ++i)
//		sort_board.push_back(i + 1);
//
//	queue<vector<int>> q;
//	q.push(board);
//	while (!q.empty() && result < 0)
//	{
//		vector<int> tmp = q.front();
//		q.pop();
//		if (tmp == sort_board)
//			result = m[tmp];
//		else
//			for (size_t i = 0; i + k < n + 1; ++i)
//			{
//				vector<int> check_tmp = tmp;
//				reverse(check_tmp.begin() + i, check_tmp.begin() + i + k);
//
//				if (!m.count(check_tmp))
//				{
//					m[check_tmp] = m[tmp] + 1;
//					q.push(check_tmp);
//				}
//			}
//	}
//	return result;
//}

vector<int> BFS(Graph& g, int i = 0)
{
	vector<int> board;

	int* check = new int[g.get_size()];
	for (int i = 0; i < g.get_size(); ++i)
		check[i] = 0;

	queue<int> q;
	check[i] = 1;
	q.push(i);
	while (!q.empty())
	{
		i = q.front();
		q.pop();
		board.push_back(i + 1);

		for (int j = 0; j < g.get_size(); ++j)
			if (g.get_matrix()[i][j] && !check[j])
			{
				check[j] = 1;
				q.push(j);
			}
	}
	return board;
}

int find_min(vector<int> board, int n, int k)
{
	int result = -1;
	map<vector<int>, int> Map;
	vector<int> sort_board;

	for (size_t i = 0; i < n; ++i)
		sort_board.push_back(i + 1);

	queue<vector<int>> qq;
	qq.push(board);
	while (!qq.empty() && result < 0)
	{
		vector<int> new_board = qq.front();
		qq.pop();
		if (new_board == sort_board)
			result = Map[new_board];
		else
			for (size_t i = 0; i + k < n + 1; ++i)
			{
				vector<int> tmp_board = new_board;
				reverse(tmp_board.begin() + i, tmp_board.begin() + i + k);

				if (!Map.count(tmp_board))
				{
					Map[tmp_board] = Map[new_board] + 1;
					qq.push(tmp_board);
				}
			}
	}
	return result;
}

void init_graph(int n, int** graph)
{
	for (size_t i = 0; i < n; ++i)
		for (size_t j = 0; j < n; ++j)
			graph[i][j] = 0;
}

void test_1(int n, int k)
{
	auto inputGraph = [](Graph& graph)
	{
		graph.add_edge(1, 2);
		graph.add_edge(2, 3);
	};

	int** graph = new int* [n];
	for (size_t i = 0; i < n; ++i)
		graph[i] = new int[n];

	init_graph(n, graph);
	Graph A(n, graph);
	inputGraph(A);

	vector<int> board = BFS(A);
	cout << n << ' ' << k << '\n';
	for (size_t i = 0; i < board.size(); ++i)
		cout << board.at(i) << ' ';
	cout << '\n';
	cout << find_min(board, n, k) << '\n' << '\n';
}

void test_2(int n, int k)
{
	auto inputGraph = [](Graph& graph)
	{
		graph.add_edge(3, 2);
		graph.add_edge(2, 1);
	};

	int** graph = new int* [n];
	for (size_t i = 0; i < n; ++i)
		graph[i] = new int[n];

	init_graph(n, graph);
	Graph A(n, graph);
	inputGraph(A);

	vector<int> board = BFS(A, 2);
	cout << n << ' ' << k << '\n';
	for (size_t i = 0; i < board.size(); ++i)
		cout << board.at(i) << ' ';
	cout << '\n';
	cout << find_min(board, n, k) << '\n' << '\n';
}

void test_3(int n, int k)
{
	auto inputGraph = [](Graph& graph)
	{
		graph.add_edge(7, 2);
		graph.add_edge(2, 1);
		graph.add_edge(1, 6);
		graph.add_edge(6, 8);
		graph.add_edge(8, 4);
		graph.add_edge(4, 3);
		graph.add_edge(3, 5);
	};

	int** graph = new int* [n];
	for (size_t i = 0; i < n; ++i)
		graph[i] = new int[n];

	init_graph(n, graph);
	Graph A(n, graph);
	inputGraph(A);

	vector<int> board = BFS(A, 6);
	cout << n << ' ' << k << '\n';
	for (size_t i = 0; i < board.size(); ++i)
		cout << board.at(i) << ' ';
	cout << '\n';
	cout << find_min(board, n, k) << '\n' << '\n';
}

void test_4(int n, int k)
{
	auto inputGraph = [](Graph& graph)
	{
		graph.add_edge(3, 2);
		graph.add_edge(2, 4);
		graph.add_edge(4, 1);
		graph.add_edge(1, 5);
	};

	int** graph = new int* [n];
	for (size_t i = 0; i < n; ++i)
		graph[i] = new int[n];

	init_graph(n, graph);
	Graph A(n, graph);
	inputGraph(A);

	vector<int> board = BFS(A, 2);
	cout << n << ' ' << k << '\n';
	for (size_t i = 0; i < board.size(); ++i)
		cout << board.at(i) << ' ';
	cout << '\n';
	cout << find_min(board, n, k) << '\n' << '\n';
}

void test_5(int n, int k)
{

	vector<int> board;
	board.push_back(5);
	board.push_back(4);
	board.push_back(1);
	board.push_back(3);
	board.push_back(2);
	cout << n << ' ' << k << '\n';
	for (size_t i = 0; i < board.size(); ++i)
		cout << board.at(i) << ' ';
	cout << '\n';
	cout << find_min(board, n, k) << '\n' << '\n';
}

int main()
{
	test_1(3, 3);
	test_2(3, 3);
	test_3(8, 4);
	test_4(5, 4);
	cin.get();
	return 0;
}

